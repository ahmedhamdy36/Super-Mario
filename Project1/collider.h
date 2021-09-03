#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class collider
{
	RectangleShape& body;
public:
	collider(RectangleShape& body);
	
	void Move(float dx, float dy)
	{
		body.move(dx, dy);
	}

	bool checkCollision(collider& other, Vector2f& direction,float push);
	
	Vector2f getPosition()
	{
		return body.getPosition();
	}

	Vector2f getHalfSize()
	{
		return (body.getSize() / 2.0f);
	}

	~collider();
};

