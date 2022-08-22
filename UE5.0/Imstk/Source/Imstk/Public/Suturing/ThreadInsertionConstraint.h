// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imstkPbdCollisionConstraint.h"
#include "imstkMath.h"
#include "imstkVecDataArray.h"

/**
 * 
 */
class IMSTK_API ThreadInsertionConstraint : public imstk::PbdCollisionConstraint
{
private:

	imstk::Vec2d m_threadBaryPt;
	imstk::Vec3d m_triangleBaryPt;
	imstk::Vec3d m_triInsertionPoint;
	imstk::Vec3d m_threadInsertionPoint;

public:

	ThreadInsertionConstraint() : imstk::PbdCollisionConstraint(2, 3) // (num thread verts, num triangle verts)
	{
	}

	~ThreadInsertionConstraint() override = default;

public:

	void initConstraint(
		imstk::VertexMassPair ptA1,
		imstk::VertexMassPair ptA2,
		imstk::Vec2d          threadBaryPoint,
		imstk::VertexMassPair ptB1,
		imstk::VertexMassPair ptB2,
		imstk::VertexMassPair ptB3,
		imstk::Vec3d          triBaryPoint,
		double         stiffnessA,
		double         stiffnessB);

	bool computeValueAndGradient(
		double& c,
		std::vector<imstk::Vec3d>& dcdxA,
		std::vector<imstk::Vec3d>& dcdxB) const override;
};
