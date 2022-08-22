// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imstkPbdObjectCollision.h"
#include "imstkPbdObject.h"
#include "NeedleObject.h"

/**
 * 
 */
class IMSTK_API NeedleInteraction : public imstk::PbdObjectCollision
{
public:
	NeedleInteraction(std::shared_ptr<imstk::PbdObject>    tissueObj,
		std::shared_ptr<NeedleObject> needleObj,
		std::shared_ptr<imstk::PbdObject>    threadObj);
	~NeedleInteraction() override = default;

	IMSTK_TYPE_NAME(NeedleInteraction)

		void stitch();
};
