// Fill out your copyright notice in the Description page of Project Settings.


#include "TwoWayPbdConstraint.h"
#include "imstkPbdContactConstraint.h"
#include "imstkPbdModel.h"
#include "imstkPbdModelConfig.h"

void UTwoWayPbdConstraint::Init()
{
    // Creates a two way constraint between a needle and line mesh
    std::shared_ptr<imstk::PbdModel> PbdModel = std::dynamic_pointer_cast<imstk::PbdObject>(Thread->ImstkCollidingObject)->getPbdModel();

    PbdModel->getConfig()->addPbdConstraintFunctor([=](imstk::PbdConstraintContainer& Container)
        {
            const imstk::Vec3d EndOfNeedle = (*std::dynamic_pointer_cast<imstk::LineMesh>(NeedleObj->ImstkCollidingObject->getCollidingGeometry())->getVertexPositions())[0];
            auto attachmentConstraint = std::make_shared<imstk::PbdBodyToBodyDistanceConstraint>();
            attachmentConstraint->initConstraint(PbdModel->getBodies(),
                { std::dynamic_pointer_cast<imstk::PbdObject>(NeedleObj->ImstkCollidingObject)->getPbdBody()->bodyHandle, 0 },
                EndOfNeedle,
                { std::dynamic_pointer_cast<imstk::PbdObject>(Thread->ImstkCollidingObject)->getPbdBody()->bodyHandle, 0 }, 
                RestLength,                             
                Compliance);
            Container.addConstraint(attachmentConstraint);
        });
    GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Two way constraint initialized between " + NeedleObj->GetName() + " and " + Thread->GetName(), FColor::Green);
}