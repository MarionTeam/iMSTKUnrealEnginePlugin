// Fill out your copyright notice in the Description page of Project Settings.


#include "ThreadInsertionConstraint.h"


void
ThreadInsertionConstraint::initConstraint(
	imstk::VertexMassPair ptA1,
	imstk::VertexMassPair ptA2,
	imstk::Vec2d          threadBaryPoint,
	imstk::VertexMassPair ptB1,
	imstk::VertexMassPair ptB2,
	imstk::VertexMassPair ptB3,
	imstk::Vec3d          triBaryPoint,
	double         stiffnessA,
	double         stiffnessB)
{
	// Vertex mass pairs for thread
	m_bodiesFirst[0] = ptA1;
	m_bodiesFirst[1] = ptA2;

	// Barycentric coordinate on thread of intersection point
	m_threadBaryPt = threadBaryPoint;

	// Computing world coordinates of intersecting point along thread
	m_threadInsertionPoint = m_threadBaryPt[0] * (*m_bodiesFirst[0].vertex)
		+ m_threadBaryPt[1] * (*m_bodiesFirst[1].vertex);

	// Vertex mass pairs for triangle
	m_bodiesSecond[0] = ptB1;
	m_bodiesSecond[1] = ptB2;
	m_bodiesSecond[2] = ptB3;

	// Barycentric coordinate of puncture point on triangle
	m_triangleBaryPt = triBaryPoint;

	// Computing world coordinates of puncture point
	m_triInsertionPoint = m_triangleBaryPt[0] * (*m_bodiesSecond[0].vertex)
		+ m_triangleBaryPt[1] * (*m_bodiesSecond[1].vertex)
		+ m_triangleBaryPt[2] * (*m_bodiesSecond[2].vertex);

	// Saving stiffness
	m_stiffnessA = stiffnessA;
	m_stiffnessB = stiffnessB;
}

bool
ThreadInsertionConstraint::computeValueAndGradient(
	double& c,
	std::vector<imstk::Vec3d>& dcdxA,
	std::vector<imstk::Vec3d>& dcdxB) const
{
	// Move thread such that the thread stays intersected with the
	// puncture point on the triangle

	imstk::Vec3d diff = m_triInsertionPoint - m_threadInsertionPoint;  // gradient dcdx
	c = diff.norm();

	// If sufficiently close, do not solve constraint
	if (c < 1E-8)
	{
		return false;
	}

	diff.normalize();

	// Move thread to follow insertion point
	dcdxA[0] = diff * m_threadBaryPt[0];
	dcdxA[1] = diff * m_threadBaryPt[1];

	// Move triangle to follow thread point (WARNING: Currently inactive)
	dcdxB[0] = imstk::Vec3d::Zero();
	dcdxB[1] = imstk::Vec3d::Zero();
	dcdxB[2] = imstk::Vec3d::Zero();

	return true;
}
