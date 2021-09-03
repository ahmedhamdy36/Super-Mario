#include "animation.h"

animation::animation(Texture* texture, Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

void animation::update(int row, float changeTime, bool direction)
{
	currentImage.y = row;
	totalTime = totalTime + changeTime;

	if (totalTime >= switchTime)
	{
		totalTime = totalTime - switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}

	uvRect.top = currentImage.y*uvRect.height;
	
	if (direction)
	{
		uvRect.left = currentImage.x *uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) *abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

animation::~animation()
{

}