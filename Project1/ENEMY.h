#pragma once
#include<SFML\Graphics.hpp>
#include"animation.h"
#include"collider.h"
using namespace sf;

class ENEMY
{
	RectangleShape body;
	animation animy;
	int row;
	float speed;
	bool direction;
	Vector2f velocity;
public:
	ENEMY(Texture* texture, Vector2u imageCount, float switchTime, float speed);

	void update(float changeTime);
	void draw(RenderWindow& window);
	void onCollision(Vector2f direction);

	/*
	void GetPosition()
	{
		
	}
	*/

	collider getCollider()
	{
		return collider(body);
	}

	~ENEMY();
};