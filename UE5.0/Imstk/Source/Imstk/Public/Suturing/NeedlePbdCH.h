/*
** This file is part of the Interactive Medical Simulation Toolkit (iMSTK)
** iMSTK is distributed under the Apache License, Version 2.0.
** See accompanying NOTICE for details.
*/

#pragma once

#include "imstkMacros.h"
#include "imstkPbdCollisionHandling.h"
#include "imstkPbdPointTriangleConstraint.h"
#include "imstkSurfaceMesh.h"
//#include "imstkLineMesh.h"

#include "NeedleObject.h"
#include "SurfaceInsertionConstraint.h"
#include "ThreadInsertionConstraint.h"

class PbdObject;
class PbdBaryPointToPointConstraint;
class LineMesh;
class TetrahedralMesh;

/// \class NeedlePbdCH
///
/// \brief Handles penetration constraints for the needle and the thread by creating a set of puncture points
/// that are used to find the nearest segment on either the needle or the thread and constraining the tissue to the
/// needle, or the thread to the tissue. This class assumes the mesh is not cut or otherwise modified during runtime.
///
class NeedlePbdCH : public imstk::PbdCollisionHandling
{
protected:
	// Stores data for penetration points, both for the needle and the thread
	struct SuturePenetrationData
	{
		// Triangle ID
		int triId = -1;

		// Triangle vertices
		imstk::Vec3d* triVerts[3] = { nullptr, nullptr, nullptr };
		imstk::Vec3i triVertIds = { -1, -1, -1 };

		// Puncture barycentric coordinate on triangle
		imstk::Vec3d triBaryPuncturePoint = { 0.0, 0.0, 0.0 };
	};

	imstk::Vec3d m_needleDirection = imstk::Vec3d::Zero();

	// Flags for which entity is puncturing a triangle
	std::vector<bool> m_isNeedlePunctured;
	std::vector<bool> m_isThreadPunctured;

	// Vector of needle-triangle constraints (one sided, force triangle to follow needle)
	std::vector<std::shared_ptr<SurfaceInsertionConstraint>> pointTriangleConstraints;

	// Vector of thread-triangle constraints (one sided, force thread to follow triangle)
	std::vector<std::shared_ptr<imstk::PbdBaryPointToPointConstraint>> m_stitchConstraints;

	// Center of puncture points for stitching constraint
	imstk::Vec3d m_stitchCenter = imstk::Vec3d::Zero();

	// Storage for penetration data for both the needle and the thread
	std::vector<SuturePenetrationData> m_needlePData;
	std::vector<SuturePenetrationData> m_threadPData;

	// Bool to activate stitching constraint
	bool m_stitch = false;

	// Thread Data
	std::shared_ptr<imstk::PbdObject> m_threadObj;
	std::shared_ptr<imstk::LineMesh>  m_threadMesh;
	std::shared_ptr<imstk::VecDataArray<double, 3>> m_threadVerticesPtr;

	// PBD Tissue Mesh Data
	std::shared_ptr<imstk::PbdObject>   m_pbdTissueObj;
	std::shared_ptr<imstk::SurfaceMesh> m_tissueSurfMesh;
	std::shared_ptr<imstk::VecDataArray<double, 3>> m_meshVerticesPtr;

	// Fake velocity for stitch constraint
	imstk::Vec3d m_fakeVelocity = imstk::Vec3d::Zero();

public:
	NeedlePbdCH() = default;
	~NeedlePbdCH() override = default;

	IMSTK_TYPE_NAME(NeedlePbdCH)

		///
		/// \brief Initialize interaction data
		///
		void init(std::shared_ptr<imstk::PbdObject> threadObj);

	///
	/// \brief Create stitching constraints on button press for four or more puncture points
	///
	void stitch();

	///
	/// \brief Handles puncture constraints for both the needle and the thread
	///
	void handle(
		const std::vector<imstk::CollisionElement>& elementsA,
		const std::vector<imstk::CollisionElement>& elementsB) override;

	///
	/// \brief Add a vertex-triangle constraint
	///
	void addVTConstraint(
		imstk::VertexMassPair ptA,
		imstk::VertexMassPair ptB1, imstk::VertexMassPair ptB2, imstk::VertexMassPair ptB3,
		double stiffnessA, double stiffnessB) override;
};
