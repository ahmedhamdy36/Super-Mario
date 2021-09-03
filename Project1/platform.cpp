#include "platform.h"


platform::platform(Texture*texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}

void platform::Draw(RenderWindow&window)
{
	window.draw(body);
}

platform::~platform()
{
}
