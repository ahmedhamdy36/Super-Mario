#include "ENEMY.h"

ENEMY::ENEMY(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
animy(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	direction = true;
	body.setSize(Vector2f(40.0f, 50.0f));
	body.setPosition(500.0f, 300.0f);
	body.setTexture(texture);
}

void ENEMY::update(float changeTime)
{
	velocity.x = 0.0f;
	velocity.x += speed;

	if (velocity.x == 0.0f)
		row = 0;
	else
	{
		row = 1;
		if (velocity.x>0.0f)
			direction = true;
		else
			direction = false;
	}

	animy.update(row, changeTime, direction);
	body.setTextureRect(animy.uvRect);
	body.move(velocity*changeTime);
}

void ENEMY::draw(RenderWindow& window)
{
	window.draw(body);
}

void ENEMY::onCollision(Vector2f direction)
{
	if (direction.x<0.0f)
		velocity.x = 0.0f;
	else if (direction.x>0.0f)
		velocity.x = 0.0f;
	
	if (direction.y<0.0f)
		velocity.y = 0.0f;
	else if (direction.y > 0.0f)
		velocity.y = 0.0f;
}
/*
void ENEMY::GetPosition()
{
	if (body.getPosition().x==1500.0f)
	{

	}
	if (body.getPosition().x==1100.0f)
	{

	}
}
*/
ENEMY::~ENEMY()
{

}


