#include "Engine.h"
#include "Components/PlayerComponent.h"

#include <iostream>
#include <cstdlib>
#include <vector>
/*
void func1(int i) { std::cout << "func1: " << i << std::endl; }
void func2(int i) { std::cout << "func2: " << i << std::endl; }
*/
int main(int argc, char* argv[])
{
	/*
	void (*fp)(int);
	fp = &func1;
	fp(5);
	*/

	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	// !! this code is not neccessary, it just shows the contents of the file !!
	std::string buffer;
	File::ReadFile("Scenes/scene.json", buffer);
	// show the contents of the json file
	std::cout << buffer << std::endl;

	// read json
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	// create, read and initialize scene
	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();
		
	while (!engine->IsQuit())
	{
		// update
		engine->Update();
		scene->Update(engine->GetTime().GetDeltaTime());

		auto* actor = scene->GetActor<Actor>("text");
		if (actor) {
			actor->transform.scale = 1.0f + Math::Sin(engine->GetTime().GetTime()) * 5;
			actor->transform.rotation += 90 * engine->GetTime().GetDeltaTime();
		}

		// render
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		scene->Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	scene->RemoveAll();
	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}
