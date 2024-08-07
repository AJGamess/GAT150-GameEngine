#pragma once
#include "RenderComponent.h"
#include "../Renderer/Texture.h"
#include "..\Renderer\Renderer.h"


class TextureComponent : public RenderComponent
{
public:
	void Intialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;
public:
	std::string textureName;
	//res_t<Texture> texture;
};