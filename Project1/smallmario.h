#pragma once
#include<SFML\Graphics.hpp>
#include"animation.h"
#include"collider.h"
using namespace sf;
class smallmario
{
	RectangleShape body;
	animation animy;
	int row;
	float speed, jumpHight;
	bool direction, canJump;
	Vector2f velocity;
public:
	smallmario(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHight);
	
	void update(float changeTime);
	void draw(RenderWindow& window);
	void onCollision(Vector2f direction);

	Vector2f GetPosition()
	{
		return body.getPosition();
	}

	collider getCollider()
	{
		return collider(body);
	}

	~smallmario();
};