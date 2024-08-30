#include "RocketComponent.h"
#include "EnemyComponent.h"
#include "PlayerComponent.h"
#include "Components/TextComponent.h"
#include "Engine.h"

FACTORY_REGISTER(RocketComponent)

void RocketComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&RocketComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void RocketComponent::Update(float dt)
{
	owner->GetComponent<PhysicsComponent>()->SetVelocity(owner->transform.Forward() * speed);
}

void RocketComponent::OnCollisionEnter(Actor* actor)
{
    // Get the components from the actors
    auto enemyComponent = actor->GetComponent<EnemyComponent>();
    auto playerComponent = actor->GetComponent<PlayerComponent>();
    if (!actor->destroyed && actor->name == "enemy") {       
        
        enemyComponent->lifepoints -= 1;

        // Check if the enemy is dead
        if (enemyComponent->lifepoints <= 0) {
            actor->destroyed = true;
            UpdateWinText("Player wins!");
        }
        std::cout << "player rocket hit enemy\n";
    }
    else if (!actor->destroyed && actor->name == "player") {
        
        playerComponent->lifepoints -= 1;

        // Check if the player is dead
        if (playerComponent->lifepoints <= 0) {
            actor->destroyed = true;
            UpdateWinText("Enemy wins!");
        }
        std::cout << "enemy rocket hit player\n";
    }

    
}

void RocketComponent::UpdateWinText(const std::string& newText)
{
    Actor* textActor = owner->scene->GetActorByName("text");
    if (textActor)
    {
        // Get the TextComponent from the text actor
        auto textComponent = textActor->GetComponent<TextComponent>();
        if (textComponent)
        {
            std::cout << "Updating text to: " << newText << std::endl;
            // Update the text to display the winner
            textComponent->SetText(newText);
        }
    }
}


void RocketComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void RocketComponent::Write(json_t& value)
{
	//
}
