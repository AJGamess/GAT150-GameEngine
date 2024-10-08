#pragma once
#include "PhysicsComponent.h"

class EnginePhysicsComponent : public PhysicsComponent
{
public:
	CLASS_DECLARATION(EnginePhysicsComponent)
	CLASS_PROTOTYPE(EnginePhysicsComponent)

	void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const Vector2& force) override;
	void ApplyTorque(float torque) override { }
	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }
};