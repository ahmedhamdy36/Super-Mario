#pragma once
#include<SFML\Graphics.hpp>
using namespace sf;

class animation
{
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;

public:
	IntRect uvRect;
	animation(Texture* texture, Vector2u imageCount, float switchTime);
	void update(int row, float changeTime, bool direction);
	~animation();
};