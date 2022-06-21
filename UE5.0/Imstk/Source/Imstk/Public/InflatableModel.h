// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PBDModel.h"
#include "imstkPbdConstraintContainer.h"
#include "InflatableModel.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UInflatableModel : public UPBDModel
{
	GENERATED_BODY()

public:
	void Inject(const FVector ToolTip, const double Radius, double Rate);

	virtual void Init() override;

protected:
	void FindAffectedConstraint(const FVector ToolTip, const double Radius);

	inline double ComputeGaussianWeight(double x) { return 10 * exp(-0.5 * x * x / Sigma / Sigma) / Sigma; }

	double Sigma = 1.0;

	TArray<TPair<int, double>> ConstraintIDandWeight;

	std::shared_ptr<imstk::PbdConstraintContainer> ConstraintContainer;

	bool bAffectedAreaUpdated = false;
	
};
