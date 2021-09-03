#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>
#include<assert.h>
#include<fstream>
#include<cctype>
#include<string>
#include<ctime>
#include<cstdlib>

#define ll long long 
#define forn(i,n)  for(int i=0  ;i<(int) n ;i++)
#define F first 
#define S second 
#define st string 
#define Wall 1
#define Tree 2
#define space 3

using namespace std;
using namespace sf;
Sprite Tiles;
Texture Wall_Texture , Space_Texture  ,Tree_Texture ;
int main(void)
{

	RenderWindow window(VideoMode(780, 440), "Super Mario Bros", Style::Close | Style::Resize | Style::Titlebar);
	Vector2i map[270][270], loadCntr = Vector2i(0, 0);

	fstream  World11("World 1-1.txt");
	assert(World11.is_open());

	Wall_Texture.loadFromFile("wall3.jpg");
	assert(Wall_Texture.loadFromFile("wall3.jpg"));

	Space_Texture.loadFromFile("Blue.png");
	assert(Space_Texture.loadFromFile("Blue.png"));

	Tree_Texture.loadFromFile("Trees.png");
	assert(Tree_Texture.loadFromFile("Trees.png"));

	while (!World11.eof())
	{
		char pixel;
		World11 >> pixel;
		if (pixel == '0')
			map[loadCntr.x][loadCntr.y] = Vector2i(space, space); // space 
		else if (pixel == '#')
			map[loadCntr.x][loadCntr.y] = Vector2i(Wall, Wall); // Wall
		else if (pixel == 'T')
		    map[loadCntr.x][loadCntr.y] = Vector2i(Tree, Tree);// Tree
		World11.peek() == '\n' ? loadCntr.x = 0, loadCntr.y++ : loadCntr.x++;
	}
	loadCntr.y++;








	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			case Event::Closed:
				window.close();
		}
		forn(i, loadCntr.x)
		{
			forn(ii, loadCntr.y)
			{
				if (map[i][ii].x == Wall)
				{
					Tiles.setTexture(Wall_Texture);
					Tiles.setTextureRect(IntRect(0, 0, 32, 32));
					Tiles.setScale(Vector2f(1, 1));
					Tiles.setPosition(i * 32.0, ii * 32.0);
				}
				else if (map[i][ii].x == space)
				{
					Tiles.setTexture(Space_Texture);
					Tiles.setTextureRect(IntRect(0, 0, 32, 32));
					Tiles.setScale(Vector2f(1, 1));
					Tiles.setPosition(i * 32.0, ii * 32.0);
				}
				else if (map[i][ii].x == Tree)
				{
					Tiles.setTexture(Tree_Texture);
					Tiles.setTextureRect(IntRect(20, 20, 100, 100));
					Tiles.setScale(1.2, 1.2);
					Tiles.setPosition(i + 10.0, ii + 10.0);
				}
				window.draw(Tiles);
			
			
			
			}

		}


		window.display();
	}

	system("pause");
}
	



