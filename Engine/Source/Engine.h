#pragma once

//Math
#include "..\Source\Math\Vector2.h"
#include "..\Source\Math\Random.h"
#include "..\Source\Math\MathUtils.h"
#include "..\Source\Math\Color.h"
#include "..\Source\Math\Transform.h"
#include "Math/Rect.h"

//Core
#include "Core/EFile.h"
#include "Core/EAssert.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include "Core/Singleton.h"
#include "..\Source\Core\ETime.h"

//Framework
#include "Framework/Actor.h"
#include "Framework/Scene.h"

//Input
#include "..\Source\Input\Input.h"

//Renderer
#include "..\Source\Renderer\Renderer.h"
#include "..\Source\Renderer\Particle.h"
#include "..\Source\Renderer\ParticleSystem.h"
#include "..\Source\Renderer\Text.h"
#include "..\Source\Renderer\Font.h"
#include "..\Source\Renderer\Model.h"
#include "..\Source\Renderer\Texture.h"

//Audio
#include "..\Source\Audio\Audio.h"

//Physics
#include "Physics/Physics.h"

// ** resources **
#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

//Components
#include "..\Source\Components\Component.h"
#include "..\Source\Components\TextureComponent.h"
#include "..\Source\Components\TextureAnimationComponent.h"
#include "..\Source\Components\TextComponent.h"
#include "..\Source\Components\EnginePhysicsComponent.h"

//Events
#include "Events/EventSystem.h"
#include "Events/Event.h"

#include <fmod.hpp>
#include <SDL.h>
#include <memory>

#define RENDERER g_engine.GetRenderer()

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput()		{ return *m_input; }
	Audio& GetAudio()		{ return *m_audio; }
	ParticleSystem& GetPS() { return *m_particleSystem; }
	Physics& GetPhysics() { return *m_physics; }

	Time& GetTime()			{ return *m_time;  }

	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	std::unique_ptr<Time>		m_time;

	std::unique_ptr<Renderer>	m_renderer;
	std::unique_ptr<Input>		m_input;
	std::unique_ptr<Audio>		m_audio;

	std::unique_ptr<Physics> m_physics;
	
	std::unique_ptr<ParticleSystem> m_particleSystem;
};



extern Engine g_engine;

