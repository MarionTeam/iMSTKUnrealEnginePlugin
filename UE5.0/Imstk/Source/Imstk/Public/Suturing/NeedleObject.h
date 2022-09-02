// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imstkRigidObject2.h"
#include "imstkMacros.h"

/**
 * 
 */

class IMSTK_API NeedleObject : public imstk::RigidObject2
{
public:
	enum class CollisionState
	{
		REMOVED,
		TOUCHING,
		INSERTED
	};

	enum class PrevCollisionState
	{
		REMOVED,
		INSERTED
	};

	NeedleObject(std::shared_ptr<imstk::RigidBodyModel2> rbdModel, USceneComponent* Comp);
	virtual ~NeedleObject() = default;

	IMSTK_TYPE_NAME(NeedleObject)

	SIGNAL(NeedleObject, inserted);
	SIGNAL(NeedleObject, removed);

	void setCollisionState(const CollisionState state)
	{
		// If current state is inserted and previous was not inserted
		if (m_collisionState == CollisionState::INSERTED && state != CollisionState::INSERTED)
		{
			this->postEvent(imstk::Event(removed()));
		}
		// If current state not inserted and previous inserted
		else if (m_collisionState != CollisionState::INSERTED && state == CollisionState::INSERTED)
		{
			this->postEvent(imstk::Event(inserted()));
		}
		m_collisionState = state;
	}

	void setPrevCollisionState(const PrevCollisionState state)
	{
		// If current state is inserted and previous was not inserted
		if (m_prevCollisionState == PrevCollisionState::INSERTED && state != PrevCollisionState::INSERTED)
		{
			this->postEvent(imstk::Event(removed()));
		}
		// If current state not inserted and previous inserted
		else if (m_prevCollisionState != PrevCollisionState::INSERTED && state == PrevCollisionState::INSERTED)
		{
			this->postEvent(imstk::Event(inserted()));
		}
		m_prevCollisionState = state;
	}

	CollisionState getCollisionState() const { return m_collisionState; }
	PrevCollisionState getPrevCollisionState() const { return m_prevCollisionState; }

	///
	/// \brief sets/gets the minimum force that needs to be applied for puncture to occru.
	/// Note: These are only useful if haptics are being used. Otherwise another metric must
	/// be used.
	/// @{
	void setForceThreshold(const double forceThreshold) { m_forceThreshold = forceThreshold; }
	double getForceThreshold() const { return m_forceThreshold; }
	///  @}

protected:
	CollisionState     m_collisionState = CollisionState::REMOVED;
	PrevCollisionState m_prevCollisionState = PrevCollisionState::REMOVED;

	double m_forceThreshold = 5.0;
};
