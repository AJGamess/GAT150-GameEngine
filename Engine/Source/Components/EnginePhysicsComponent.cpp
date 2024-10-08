#include "EnginePhysicsComponent.h"
#include "../Framework/Actor.h"

FACTORY_REGISTER(EnginePhysicsComponent)

void EnginePhysicsComponent::Initialize()
{
	//
}

void EnginePhysicsComponent::Update(float dt)
{
	velocity += acceleration * dt;
	owner->transform.position += velocity * dt;
	velocity *= 1.0f / (1.0f + damping * dt);

	acceleration = Vector2{ 0, 0 };
}
/*
void EnginePhysicsComponent::ApplyTorque(float torque) {
	owner->transform.rotation += torque;
}
*/

void EnginePhysicsComponent::ApplyForce(const Vector2& force)
{
	assert(mass != 0);
	// acceleration = F + F + F
	// f = ma
	// a = f / m
	acceleration += force / mass;
}

void EnginePhysicsComponent::SetPosition(const Vector2& position)
{
	owner->transform.position = position;
}

void EnginePhysicsComponent::Read(const json_t& value)
{
	PhysicsComponent::Read(value);
}

void EnginePhysicsComponent::Write(json_t& value)
{
}