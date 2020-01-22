#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include "loadAssets.h"

//Compiler Directives
using namespace std;
using namespace sf;

RenderWindow window(VideoMode(832, 576), "Fishy Waters"); // 13 squares wide, 9 square high

LoadAssets loadAssets;

void gameAssets()
{

}

int main()
{
//Local Variables
	//Event Variables
	Event event;

	Sprite Grass = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_020", "png");
	Sprite Water = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_030", "png");


	int fishyWorld[50][40];
	int mapSizeWidth = 50; //unsure if im happy with the name 943
	int mapSizeHeight = 40; //unsure if im happy with the name 943

	ifstream fishyMap("Assets/Map.txt");
	int i, j;

	for(i=0; i < mapSizeWidth; i++)
	{
		for(j=0; j < mapSizeHeight; j++)
		{
			fishyMap>>fishyWorld[i][j];
		}
	}
	
	while (window.isOpen()) //The Game Window Loop
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
		}
		window.clear(sf::Color(100,100,100));

		int startI = 13;
		int startJ = 6;
		for(i = 13; i < 26; i++)
		{
			for(j = 6; j < 15; j++)
			{
				if(fishyWorld[i][j] == 14)
				{
					//Grass
					Grass.setPosition((i-startI)*64, (j-startJ)*64);
					window.draw(Grass);
				}
				else if(fishyWorld[i][j] == 04)
				{
					//Water
					Water.setPosition((i-startI)*64, (j-startJ)*64);
					window.draw(Water);
				}
			}
		}

		window.display();
	}
	return 0;
}