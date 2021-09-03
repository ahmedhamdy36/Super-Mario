#include<SFML\Audio.hpp>
#include "smallmario.h"

smallmario::smallmario(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHight) :
animy(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHight=jumpHight;
	row = 0;
	direction = true;
	body.setSize(Vector2f(40.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(250.0f, 250.0f);
	body.setTexture(texture);
}

void smallmario::update(float changeTime)
{
	velocity.x = 0.0f;

	if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
		velocity.x -= speed;

	if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
		velocity.x += speed;

	if (Keyboard::isKeyPressed(Keyboard::Key::Space)&& canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f*981.0f*jumpHight);
	}

	velocity.y += 981.0f*changeTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
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

void smallmario::draw(RenderWindow& window)
{
	window.draw(body);
}

void smallmario::onCollision(Vector2f direction)
{
	if (direction.x<0.0f)
		velocity.x = 0.0f;
	else if (direction.x>0.0f)
		velocity.x = 0.0f;
	if (direction.y<0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
		velocity.y = 0.0f;
}

smallmario::~smallmario()
{

}


