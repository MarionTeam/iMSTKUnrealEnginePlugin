#pragma once
#include "CoreMinimal.h"
#include "imstkPbdDistanceConstraint.h"
//#include "imstkPbdConstraintFunctor.h"

class IMSTK_API PbdInflatableDistanceConstraint : public imstk::PbdDistanceConstraint
{
public:
    PbdInflatableDistanceConstraint() : imstk::PbdDistanceConstraint() {}

    
    ///
    /// \brief Initializes the inflatable distance constraint
    ///
    void initConstraint(const imstk::VecDataArray<double, 3>& initVertexPositions,
        const size_t& pIdx0,
        const size_t& pIdx1,
        const double k = 1e5)
    {
        imstk::PbdDistanceConstraint::initConstraint(initVertexPositions, pIdx0, pIdx1, k);
        m_initialRestLength = m_restLength;
        m_initialStiffness = m_stiffness;
    }

    ///
    /// \brief Apply diffusion and update positions
    ///
    void projectConstraint(const imstk::DataArray<double>& currInvMasses,
        const double dt,
        const SolverType& type,
        imstk::VecDataArray<double, 3>& pos) override
    {
        if (isInflated())
        {
            m_restLength =
                m_restLength + m_diffusionRate * dt * (m_initialRestLength - m_restLength);
            m_stiffness = m_stiffness + m_diffusionRate * dt * (m_initialStiffness - m_stiffness);
        }
        imstk::PbdConstraint::projectConstraint(currInvMasses, dt, type, pos);
    }

    void setRestLength(const double restLength) { m_restLength = restLength; }
    const double getRestLength() const { return m_restLength; }

    void setInitRestLength(const double initRestLength) { m_initialRestLength = initRestLength; }
    const double getInitRestLength() const { return m_initialRestLength; }

    ///
    /// \brief Reset constraint rest measurement
    ///
    void resetRestLength() { m_restLength = m_initialRestLength; }
    void resetStiffness() { m_stiffness = m_initialStiffness; }

    bool isInflated() const { return m_inflated; }
    void setInflated() { m_inflated = true; }

    double getCurrentLength(std::shared_ptr<imstk::VecDataArray<double, 3>> currVertexPositions)
    {
        imstk::VecDataArray<double, 3> positions = *currVertexPositions;
        imstk::Vec3d                   p0 = positions[m_vertexIds[0]];
        imstk::Vec3d                   p1 = positions[m_vertexIds[1]];

        return (p1 - p0).norm();
    }

public:
    double m_initialRestLength = 0.0;
    double m_initialStiffness = 1.0;
    double m_diffusionRate = 0.00001;

    bool m_inflated = false;
};

//struct PbdInflatableDistanceConstraintFunctor : public imstk::PbdDistanceConstraintFunctor
//{
//public:
//    PbdInflatableDistanceConstraintFunctor() : imstk::PbdDistanceConstraintFunctor() {}
//    ~PbdInflatableDistanceConstraintFunctor() override = default;
//
//    ///
//    /// \brief Create the distance constraint
//    ///
//    std::shared_ptr<imstk::PbdDistanceConstraint> makeDistConstraint(
//        const imstk::VecDataArray<double, 3>& vertices,
//        size_t i1, size_t i2) override
//    {
//        auto constraint = std::make_shared<PbdInflatableDistanceConstraint>();
//        constraint->initConstraint(vertices, i1, i2, m_stiffness);
//        return constraint;
//    }
//};

