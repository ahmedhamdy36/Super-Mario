#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>

#include<iostream>
#include<vector>

#include"smallmario.h"
#include"platform.h"
#include"ENEMY.h"

using namespace std;
using namespace sf;

static const float ViewHight = 500.0f;

void ResivedView(const RenderWindow& window, View &view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(ViewHight * aspectRatio, ViewHight);
}

int main()
{
	RenderWindow window(VideoMode(500, 500), "mario", Style::Close | Style::Resize);
	View view(Vector2f(0.0f, 0.0f), Vector2f(ViewHight,ViewHight));

	SoundBuffer buffer;
	buffer.loadFromFile("mapVoice2.ogg");
	Sound sound(buffer);
	sound.setVolume(400);
	sound.play();

	Texture mario, land1, land2, wall1 , wall2 , stone4, stone3 , stone2 , stone1 , monester;

	mario.loadFromFile("superMario.png");
	land1.loadFromFile("land1.png");
	land2.loadFromFile("land2.png");
	wall1.loadFromFile("wall1.png");
	wall2.loadFromFile("wall2.png");
	wall2.loadFromFile("wall2.png");
	stone4.loadFromFile("stone4.png");
	stone3.loadFromFile("stone3.png");
	stone2.loadFromFile("stone2.png");
	stone1.loadFromFile("stone1.png");
	monester.loadFromFile("monester.png");

	smallmario s_mario(&mario, Vector2u(5, 2), 0.2f, 200.0f, 200.0f);
	ENEMY mon(&monester, Vector2u(2, 2), 0.2,  100.0f);

	vector<platform> platforms;
	platforms.push_back(platform(&wall1,  Vector2f(300.0f,  700.0f), Vector2f(150.0f,  0.0f)));    //first wall
	platforms.push_back(platform(&land1,  Vector2f(3000.0f, 300.0f), Vector2f(1500.0f, 500.0f)));  //land 1
	platforms.push_back(platform(&wall2,  Vector2f(100.0f,  150.0f), Vector2f(1000.0f, 275.0f)));  //secound wall 
	platforms.push_back(platform(&stone4, Vector2f(200.0f,  50.0f),  Vector2f(700.0f,  100.0f)));  //first stones
	platforms.push_back(platform(&wall2,  Vector2f(100.0f,  150.0f), Vector2f(1500.0f, 275.0f)));  //third wall
	platforms.push_back(platform(&stone3, Vector2f(150.0f,  50.0f),  Vector2f(2150.0f, 325.0f)));  //secound stones
	platforms.push_back(platform(&stone2, Vector2f(100.0f,  50.0f),  Vector2f(2175.0f, 275.0f)));  //third stones
	platforms.push_back(platform(&stone1, Vector2f(50.0f,   50.0f),  Vector2f(2200.0f, 225.0f)));  //fourth stones
	platforms.push_back(platform(&wall1,  Vector2f(300.0f,  300.0f), Vector2f(2375.0f, 200.0f)));  //fifth wall
	platforms.push_back(platform(&land2,  Vector2f(1000.0f, 300.0f), Vector2f(3750.0f, 500.0f)));  //land 2
	platforms.push_back(platform(&wall1,  Vector2f(300.0f,  700.0f), Vector2f(4100.0f, 0.0f)));    //final wall

	float changeTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		changeTime = clock.restart().asSeconds();
		
		if (changeTime>1.0f/20.0f)
			changeTime = 1.0f / 20.0f;

		Event evn;

		while (window.pollEvent(evn))
		{
			switch (evn.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				ResivedView(window, view);
				break;
			}
		}

		s_mario.update(changeTime);
		mon.update(changeTime);
		
		Vector2f direction;
		
		for (platform& platform : platforms)
		{
			if (platform.getCollider().checkCollision(s_mario.getCollider(),direction,1.0f))
				s_mario.onCollision(direction);
		}
		
		view.setCenter(s_mario.GetPosition());
	
		window.clear(Color(135, 206, 235));
		window.setView(view);
		
		for (platform& platform : platforms)
			platform.Draw(window);
		
		s_mario.draw(window);
		mon.draw(window);
		
		window.display();
	}

	system("pause");
	return 0;
}

