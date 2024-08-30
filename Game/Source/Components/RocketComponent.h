#pragma once
#include "Components/Component.h"

class RocketComponent : public Component
{
public:
	CLASS_DECLARATION(RocketComponent)
	CLASS_PROTOTYPE(RocketComponent)

	void Initialize() override;
	void Update(float dt) override;

	void OnCollisionEnter(Actor* actor);
	void UpdateWinText(const std::string& newText);

public:
	float speed{ 0 };
};
