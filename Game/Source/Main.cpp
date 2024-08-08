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
		/*
		// create texture, using shared_ptr so texture can be shared
		std::shared_ptr<Texture> texture = std::make_shared<Texture>();
		texture->Load("Yoshi.png", engine->GetRenderer());
		*/
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Yoshi.png", engine->GetRenderer());
		
		res_t<Font> font = ResourceManager::Instance().Get<Font>("mario.ttf", 15);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Yo Yo Yo!", { 1, 0, 1, 1 });
		
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

			text->Draw(engine->GetRenderer(), 300, 300);
			engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
			engine->GetPS().Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}

		//ResourceManager::Instance().Clear();
		engine->Shutdown();
	}
	return 0;
}