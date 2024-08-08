#pragma once

#include "..\Source\Renderer\Renderer.h"
#include "..\Source\Input\Input.h"
#include "..\Source\Audio\Audio.h"

#include "..\Source\Core\ETime.h"

#include "..\Source\Math\Vector2.h"
#include "..\Source\Math\Random.h"
#include "..\Source\Math\MathUtils.h"

#include "..\Source\Renderer\Particle.h"
#include "..\Source\Renderer\ParticleSystem.h"
#include "..\Source\Renderer\Text.h"
#include "..\Source\Renderer\Font.h"

#include "..\Source\Renderer\Model.h"
#include "..\Source\Renderer\Texture.h"
#include "..\Source\Math\Transform.h"

#include "..\Source\Components\Components.h"

// ** resources **
#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

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

	Time& GetTime()			{ return *m_time;  }

	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	std::unique_ptr<Time>		m_time;

	std::unique_ptr<Renderer>	m_renderer;
	std::unique_ptr<Input>		m_input;
	std::unique_ptr<Audio>		m_audio;

	std::unique_ptr<ParticleSystem> m_particleSystem;
};



extern Engine g_engine;

