#pragma once
#include "Renderer.h"
#include "Font.h"
#include "..\Math\Color.h"
#include <string>
#include <SDL.h>
#include <iostream>

class Texture;

class Text
{
public:
	Text() = default;
	Text(res_t<Font> font) : m_font{ font } {}
	//Text(Font* font) : m_font{ font } {}
	~Text() = default;

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, float x, float y);

	void SetFont(res_t<Font> font) { m_font = font; }
	res_t<Texture> GetTexture() { return m_texture; }
private:
	//Text* m_font{ nullptr };
	res_t<Font> m_font;
	res_t<Texture> m_texture{nullptr};
};

