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

	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	//Factory::Instance().Register<TextureComponent>("TextureComponent");
	//auto a = Factory::Instance().Create("Actor");

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;
	{

		// !! this code is not neccessary, it just shows the contents of the file !!
		std::string buffer;
		File::ReadFile("json.txt", buffer);
		// show the contents of the json file
		std::cout << buffer << std::endl;

		// create json document from the json file contents
		rapidjson::Document document;
		Json::Load("json.txt", document);

		// read the data from the json
		std::string name;
		int age;
		float speed;
		bool isAwake;
		Vector2 position;
		Color color;

		READ_DATA(document, name);
		READ_DATA(document, age);
		READ_DATA(document, speed);
		READ_DATA(document, isAwake);
		READ_DATA(document, position);
		READ_DATA(document, color);
		// show the data
		std::cout << name << " " << age << " " << speed << " " << isAwake << std::endl;
		std::cout << position.x << " " << position.y << std::endl;
		std::cout << color.r << " " << color.g << " " << color.b << " " << color.a << std::endl;




		/*
		// create texture, using shared_ptr so texture can be shared
		std::shared_ptr<Texture> texture = std::make_shared<Texture>();
		texture->Load("Yoshi.png", engine->GetRenderer());
		*/
		
		//Font issue atfter closing window
		/*
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Yoshi.png", engine->GetRenderer());
		
		res_t<Font> font = ResourceManager::Instance().Get<Font>("mario.ttf", 15);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Yo Yo Yo!", { 1, 0, 1, 1 });
		*/
		/*
		
		auto actor = Factory::Instance().Create<Actor>("Actor");
		actor->SetTransform(Transform{ {30,30} });
		auto component = Factory::Instance().Create<TextureComponent>(Texture::GetTypeName());
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

			//text->Draw(engine->GetRenderer(), 300, 300);
			//engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
			engine->GetPS().Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}

		//ResourceManager::Instance().Clear();
		engine->Shutdown();
	}
	return 0;
}