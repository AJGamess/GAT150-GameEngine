#pragma once
#include "..\Math\Vector2.h"
#include "..\Renderer\Renderer.h"
#include "../Resources/Resource.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

class Texture : public Resource
{
public:
	Texture() = default;
	~Texture();

	bool Load(const std::string& filename, class Renderer& renderer);

	bool Create(std::string name, ...) override;
	Vector2 GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* m_texture{ nullptr };
};