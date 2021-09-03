#pragma once
#include<SFML\Graphics.hpp>
#include"collider.h"
using namespace sf;

class platform
{
	RectangleShape body;
public:
	platform(Texture*texture, Vector2f size, Vector2f position);
	
	void Draw(RenderWindow&window);
	
	collider getCollider()
	{
		return collider(body);
	}

	~platform();
};

