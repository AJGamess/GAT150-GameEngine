#include "TextureComponent.h"
#include "..\Resources\ResourceManager.h"
#include "..\Math\Transform.h"

void TextureComponent::Intialize()
{
	if (!textureName.empty())
	{
		//texture = ResourceManager::Instance().Get<Texture>();
	}
}

void TextureComponent::Update(float dt)
{
	//
}

void TextureComponent::Draw(Renderer& renderer)
{
	//Transform transform = owner->GetTransform();
	//renderer.DrawTexture(texture.get(), transform.position.x, transform.position.y, transform.position.);
}
