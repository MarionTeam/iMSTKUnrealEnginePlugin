// Fill out your copyright notice in the Description page of Project Settings.


#include "Suturing/NeedleInteraction.h"
#include "Suturing/NeedlePbdCH.h"
#include "imstkCollisionDetectionAlgorithm.h"

NeedleInteraction::NeedleInteraction(std::shared_ptr<imstk::PbdObject>    tissueObj,
	std::shared_ptr<NeedleObject> needleObj,
	std::shared_ptr<imstk::PbdObject>    threadObj)
	: imstk::PbdObjectCollision(tissueObj, needleObj)
{
	// Check inputs

	CHECK(std::dynamic_pointer_cast<imstk::SurfaceMesh>(tissueObj->getCollidingGeometry()) != nullptr) <<
		"NeedleInteraction only works with SufraceMesh collision geometry on the tissue object";

	CHECK(std::dynamic_pointer_cast<imstk::LineMesh>(needleObj->getCollidingGeometry()) != nullptr) <<
		"NeedleInteraction only works with LineMesh collision geometry on NeedleObject";

	CHECK(threadObj != nullptr) << "NeedleInteraction requires a PbdObject thread";

	// Add collision handler for the PBD reaction
	auto needlePbdCH = std::make_shared<NeedlePbdCH>();
	needlePbdCH->setInputObjectA(tissueObj);
	needlePbdCH->setInputObjectB(needleObj);
	needlePbdCH->setInputCollisionData(getCollisionDetection()->getCollisionData());
	needlePbdCH->init(threadObj);
	setCollisionHandlingAB(needlePbdCH);
}

void
NeedleInteraction::stitch()
{
	auto CH = std::dynamic_pointer_cast<NeedlePbdCH>(this->getCollisionHandlingAB());
	CH->stitch();
}