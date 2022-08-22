// Fill out your copyright notice in the Description page of Project Settings.


#include "SurfaceInsertionConstraint.h"

void
SurfaceInsertionConstraint::initConstraint(
	imstk::Vec3d          insertionPoint,
	imstk::VertexMassPair ptB1,
	imstk::VertexMassPair ptB2,
	imstk::VertexMassPair ptB3,
	imstk::Vec3d          contactPt,
	imstk::Vec3d          barycentricPt,
	double         stiffnessA,
	double         stiffnessB)
{
	m_insertionPoint = insertionPoint;
	m_contactPt = contactPt;
	m_barycentricPt = barycentricPt;
	m_bodiesSecond[0] = ptB1;
	m_bodiesSecond[1] = ptB2;
	m_bodiesSecond[2] = ptB3;
	m_stiffnessA = stiffnessA;
	m_stiffnessB = stiffnessB;
}

bool
SurfaceInsertionConstraint::computeValueAndGradient(
	double& c,
	std::vector<imstk::Vec3d>& dcdxA,
	std::vector<imstk::Vec3d>& dcdxB) const
{
	// Get current position of puncture point
	// Move triangle to match motion of needle

	imstk::Vec3d diff = m_contactPt - m_insertionPoint;

	c = diff.norm();

	// If sufficiently close, do not solve constraint
	if (c < 1E-8)
	{
		return false;
	}

	diff.normalize();// gradient dcdx

	// Weight by berycentric coordinates
	dcdxB[0] = diff * m_barycentricPt[0];
	dcdxB[1] = diff * m_barycentricPt[1];
	dcdxB[2] = diff * m_barycentricPt[2];

	// Dont adjust position of needle, force mesh to follow needle
	dcdxA[0] = imstk::Vec3d::Zero();

	return true;
}
