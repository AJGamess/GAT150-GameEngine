#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();
	
#ifdef _DEBUG
	std::cout << "debug\n";
#endif
	int i = 5;
	assert(i==5);


	while (!engine->IsQuit())
	{
		engine->Update();

		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		engine->GetPS().Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();

	return 0;
}