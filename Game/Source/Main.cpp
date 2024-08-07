#include "Engine.h"
#include "../Source/Core/EFile.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();
	
	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;
	{

		// create texture, using shared_ptr so texture can be shared
		std::shared_ptr<Texture> texture = std::make_shared<Texture>();
		texture->Load("Yoshi.png", engine->GetRenderer());

		/*
		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
		component->texture = texture;
		actor->AddComponent
		*/
		while (!engine->IsQuit())
		{
			//update
			engine->Update();

			//actor->Update(engine->GetTime().GetDeltaTime());

			//render
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
			engine->GetPS().Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}

		//ResourceManager::Instance().Clear();
		engine->Shutdown();
	}
	return 0;
}