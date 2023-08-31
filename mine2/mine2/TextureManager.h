#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

using std::unordered_map;
using std::string;

class TextureManager
{
	static unordered_map<string, sf::Texture> textures;
public:
	static void LoadTexture(string textureName);
	static sf::Texture& GetTexture(string textureName);
	static void Clear();
};

