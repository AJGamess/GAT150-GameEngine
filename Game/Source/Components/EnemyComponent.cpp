#include "EnemyComponent.h"
#include "Engine.h"

FACTORY_REGISTER(EnemyComponent)

void EnemyComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&EnemyComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void EnemyComponent::Update(float dt)
{
	float rotate = 0;
	float thrust = 0;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_LEFT)) rotate = -1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_RIGHT)) rotate =  1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_UP)) thrust =  1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_DOWN)) thrust = -1;

	owner->GetComponent<PhysicsComponent>()->ApplyTorque(rotate * 90 * dt);
	Vector2 direction = Vector2{ 1, 0 }.Rotate(Math::DegToRad(owner->transform.rotation));
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed * thrust);

	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_BACKSLASH))
	{
		auto rocket = Factory::Instance().Create<Actor>("rocket");
		rocket->transform.rotation = owner->transform.rotation;

		// Calculate an offset position in front of the player
		Vector2 direction = Vector2{ 1, 0 }.Rotate(Math::DegToRad(owner->transform.rotation));
		float offsetDistance = 35.0f;
		rocket->transform.position = owner->transform.position + (direction * offsetDistance);

		owner->scene->AddActor(std::move(rocket), true);
	}
}

void EnemyComponent::OnCollisionEnter(Actor* actor)
{
	EVENT_NOTIFY(PlayerDead);
	EVENT_NOTIFY_DATA(AddPoints, 100);
}

void EnemyComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void EnemyComponent::Write(json_t& value)
{
	//
}
