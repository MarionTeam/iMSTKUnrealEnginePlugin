// Fill out your copyright notice in the Description page of Project Settings.


#include "InflatableModel.h"
#include "imstkPbdModel.h"
#include "imstkCollisionUtils.h"

void UInflatableModel::Init() 
{
	Super::Init();
	ConstraintContainer = PbdObject->getPbdModel()->getConstraints();
}

void UInflatableModel::Inject(const FVector ToolTip, const double Radius, double Rate)
{
	if (bAffectedAreaUpdated)
	{
		FindAffectedConstraint(ToolTip, Radius);
	}

	for (auto& id : ConstraintIDandWeight)
	{
		const double dv = id.Value * Rate;

		auto& c = (ConstraintContainer->getConstraints())[id.Key];
		if (c->getType() == "Volume")
		{
			//const auto& constraint = std::dynamic_pointer_cast<PbdInflatableVolumeConstraint>(c);
			//constraint->setRestVolume(dv + constraint->getRestVolume());
			//constraint->setStiffness(1.0);
		}
		else if (c->getType() == "Distance")
		{
			//const auto& constraint = std::dynamic_pointer_cast<PbdInflatableDistanceConstraint>(c);
			//constraint->setRestLength(0.00001 * cbrt(dv) + constraint->getRestLength());
			//constraint->setStiffness(0.1);
		}
	}
}

void UInflatableModel::FindAffectedConstraint(const FVector ToolTip, const double Radius)
{
	ConstraintIDandWeight.Empty();
	imstk::Vec3d Min, Max;
	std::shared_ptr<imstk::TetrahedralMesh> TetMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh> (PbdObject->getPhysicsGeometry());
	TetMesh->computeBoundingBox(Min, Max);

	if (!imstk::CollisionUtils::testAabbToAabb(ToolTip[0], ToolTip[0], ToolTip[1], ToolTip[1], ToolTip[2], ToolTip[2],
		Min[0], Max[0], Min[1], Max[1], Min[2], Max[2]))
	{
		return;
	}

	std::shared_ptr<imstk::VecDataArray<double, 3>> Vertices = TetMesh->getVertexPositions();


	TArray<int> ConstraintIDs;
	TArray<double> Weights;
	int Counter = 0;
	double MinDistance = LONG_MAX;
	for (auto& c : ConstraintContainer->getConstraints())
	{
		auto& Ids = c->getVertexIds();

		FVector Center(0.0, 0.0, 0.0);
		for (auto i : Ids)
		{
			Center += UMathUtil::ToUnrealFVec((*Vertices)[i], true);
		}

		double Distance = (Center / Ids.size() - ToolTip).Normalize();

		if (Distance < Radius)
		{
			ConstraintIDs.Add(Counter);
			Weights.Add(ComputeGaussianWeight(Distance));
		}

		if (Distance < MinDistance)
		{
			MinDistance = Distance;
		}

		Counter++;
	}

	if (MinDistance > 0.5)
	{
		return;
	}
	else
	{
		for (size_t i = 0; i < ConstraintIDs.Num(); i++)
		{
			ConstraintIDandWeight.Add(TPair<int, double>(ConstraintIDs[i], Weights[i]));
		}

		bAffectedAreaUpdated = true;
	}
}