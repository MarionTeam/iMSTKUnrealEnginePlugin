// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imstkPbdCollisionConstraint.h"
#include "imstkMath.h"
#include "imstkVecDataArray.h"

/**
 * 
 */
class IMSTK_API SurfaceInsertionConstraint : public imstk::PbdCollisionConstraint
{
private:

	imstk::Vec3d m_insertionPoint;
	imstk::Vec3d m_barycentricPt;
	imstk::Vec3d m_contactPt;

public:

	///
	/// \param the Rigid body needle
	/// \param
	///
	SurfaceInsertionConstraint() : imstk::PbdCollisionConstraint(1, 3)
	{
	}

	~SurfaceInsertionConstraint() override = default;

public:

	void initConstraint(
		imstk::Vec3d          insertionPoint,
		imstk::VertexMassPair ptB1,
		imstk::VertexMassPair ptB2,
		imstk::VertexMassPair ptB3,
		imstk::Vec3d          contactPt,
		imstk::Vec3d          barycentricPt,
		double         stiffnessA,
		double         stiffnessB);

	bool computeValueAndGradient(
		double& c,
		std::vector<imstk::Vec3d>&dcdxA,
		std::vector<imstk::Vec3d>&dcdxB) const override;
};
