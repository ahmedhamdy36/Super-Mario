#include "collider.h"
#include"assert.h"
#include<iostream>


collider::collider(RectangleShape& body) :
body(body)
{

}

bool collider::checkCollision(collider& other, Vector2f& direction, float push)
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfsize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	cout << other.getPosition().x<<"\t";
	if (other.getPosition().x>2960.26)
	{
		assert(other.getPosition().y < 600);
	}

	float intersactX = abs(deltaX) - (otherHalfsize.x + thisHalfSize.x);
	float intersactY = abs(deltaY) - (otherHalfsize.y + thisHalfSize.y);

	if (intersactX < 0.0f && intersactY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);
		if (intersactX > intersactY)
		{
			if (deltaX>0.0f)
			{
				Move(intersactX * (1.0f - push), 0.0f);
				other.Move(-intersactX*push, 0.0f);
				
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				Move(-intersactX * (1.0f - push), 0.0f);
				other.Move(intersactX*push, 0.0f);
				
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY>0.0f)
			{
				Move(0.0f, intersactY * (1.0f - push));
				other.Move(0.0f, - intersactY*push);

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				Move(0.0f ,- intersactY * (1.0f - push));
				other.Move(0.0f,intersactY*push);

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}

collider::~collider()
{

}
