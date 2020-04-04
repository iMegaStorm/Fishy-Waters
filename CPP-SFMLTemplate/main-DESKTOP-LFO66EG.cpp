//updated on 18/02/2020

#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include "loadAssets.h"

//Compiler Directives
using namespace std;
using namespace sf;

RenderWindow window(VideoMode(832, 576), "Fishy Waters"); // 13 squares wide, 9 square high

LoadAssets loadAssets;

bool mapEditor = false;

bool canMove(int tileType)
{
	cout<<tileType;
	if (tileType < 20 || tileType == 55 || mapEditor) return true;

	return false;
}

void spawnFish(int fishType, int fishPositionX, int fishPositionY, Sprite fishTypes[3])
{
	Sprite fish = fishTypes[fishType];
	fish.setPosition(fishPositionX *64, fishPositionY *64);
	window.draw(fish);
}

void inputs (Sprite &ship_1, Vector2i &posBoat, int &startI, int &startJ, int worldWidth, int worldHeight, int fishyWorld[50][40])
{
	bool W = false, S = false, A = false, D = false;

	if (Keyboard::isKeyPressed(Keyboard::W) && canMove(fishyWorld[posBoat.y + startI-2][posBoat.x + startJ]))
	{
		ship_1.setRotation(180);
		if(posBoat.y + startI > 5 && posBoat.y + startI <= worldHeight - 5)
			{
				startI--;
			}
		else
			{
				posBoat.y--;
			}
		if(posBoat.y + startI < +1)
			{
				posBoat.y += 1;
			}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && canMove(fishyWorld[posBoat.y + startI][posBoat.x + startJ]))
	{
		ship_1.setRotation(0);
		if(posBoat.y + startI >= 5 && posBoat.y + startI <= worldHeight - 6)
			{
				startI++;
			}
		else
			{
				posBoat.y++;
			}
		if(posBoat.y + startI > worldHeight-1)
			{
				posBoat.y -= 1;
			}
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && canMove(fishyWorld[posBoat.y + startI -1][posBoat.x + startJ-1]))
	{
		ship_1.setRotation(90);
	if(posBoat.x + startJ >= 7 && posBoat.x + startJ <= worldWidth - 7)
		{
			startJ--;
		}
		else
		{
			posBoat.x--;
		}
		if(posBoat.x + startJ < 0)
		{
			posBoat.x += 1;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && canMove(fishyWorld[posBoat.y + startI - 1][posBoat.x + startJ+1]))
	{
		
		ship_1.setRotation(270);
	if(posBoat.x + startJ >= 6 && posBoat.x + startJ <= worldWidth - 8)
		{
			startJ++;
		}
		else
		{
			posBoat.x++;
		}
		if(posBoat.x + startJ >= worldWidth)
		{
			posBoat.x -= 1;
		}
	}
	//cout<<fishyWorld[posBoat.x + startJ][posBoat.y + startI];
	cout<< "x: "<<posBoat.x<<" y: " <<posBoat.y<<endl;
}

void gameAssets(Sprite grass_20, Sprite &grass_21, Sprite &grass_22, Sprite &grass_23, Sprite &grass_24,  Sprite &grass_25, Sprite &grass_26, Sprite &grass_27, Sprite &grass_28, Sprite &grass_29, Sprite &grass_30, Sprite &grass_31, Sprite &grass_32, Sprite &water_1, Sprite &water_4, Sprite &water_6, Sprite &ship_1, Sprite &fish1, Sprite &fish2, Sprite &fish3)
{
	grass_20 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_001", "png");
	grass_21 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_002", "png");
	grass_22 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_003", "png");
	grass_23 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_019", "png");
	grass_24 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_020", "png");
	grass_25 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_021", "png");
	grass_26 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_037", "png");
	grass_27 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_038", "png");
	grass_28 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_039", "png");
	grass_29 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_004", "png");
	grass_30 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_005", "png");
	grass_31 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_022", "png");
	grass_32 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_023", "png");

	water_1 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_012", "png");
	water_4 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_030", "png");
	water_6 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_045", "png");
	
	ship_1 = loadAssets.LoadSpriteFromTexture("Assets/", "ship_1", "png");
	ship_1.setOrigin(64.0/2, 64.0/2);
	ship_1.setRotation(270);

	fish1 = loadAssets.LoadSpriteFromTexture("Assets/", "Fish1", "png");
	fish2 = loadAssets.LoadSpriteFromTexture("Assets/", "Fish2", "png");
	fish3 = loadAssets.LoadSpriteFromTexture("Assets/", "Fish3", "png");
}

int main()
{
//Local Variables
	//Event Variables
	Event event;

	Sprite grass_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, water_1, water_4, water_6, ship_1, fish1, fish2, fish3;
	gameAssets(grass_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, water_1, water_4, water_6, ship_1, fish1, fish2, fish3);

	//RectangleShape fishyBoat;
	//fishyBoat.setSize(Vector2f(64, 64));
	//fishyBoat.setFillColor(Color(0, 0, 0));

	int fishyWorld[50][40]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height 

	//Starting position
	int startI = 0;
	int startJ = 0;

	Vector2i posBoat (4, 4); //Setting position of the boat

	ifstream fishyMap("Assets/Map.txt"); //Reading map
	
	window.setFramerateLimit(60);


	int i, j;
	srand(time(NULL));
	for(i=0; i < worldHeight; i++)
	{
		for(j=0; j < worldWidth; j++)
		{
			fishyMap>>fishyWorld[i][j];
			int randX = rand() % 6 + 2;
			int randY = rand() % 4 + 2;
			fishyWorld[randY][randX] = 2;
			
		{
			fishyWorld[i][j] = rand() %3;
		}
		}
		
	}

	Sprite fishType[3] = {fish1, fish2, fish3};

	while (window.isOpen()) //The Game Window Loop
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if(event.type == Event::KeyPressed) 
			{
				inputs(ship_1, posBoat, startI, startJ, worldWidth, worldHeight, fishyWorld);
			}
		}
		window.clear(sf::Color(100,100,100));

		for(i = startI; i < startI + 9; i++)
		{
			for(j = startJ; j < startJ + 13; j++)
			{
				if(fishyWorld[i][j] == 24)
				{
					//Grass
					grass_24.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(grass_24);
				}
				else if(fishyWorld[i][j] == 01)
				{
					water_1.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_1);
				}
				else if(fishyWorld[i][j] == 04)
				{
					//Water
					water_4.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_4);
					
				}
				else if(fishyWorld[i][j] == 55)
				{
					//water with fish
					water_4.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_4);
					spawnFish(fishyWorld[i][j],j,i, fishType);
				}
				//else if(fishyWorld[i][j] == 06)
				//{
				//	//Water
				//	water_6.setPosition((j-startJ)*64, (i-startI)*64);
				//	window.draw(water_6);
				//}
			}
		}
		ship_1.setPosition(posBoat.x*64+32, posBoat.y*64-32);
		//cout<<posBoat.y<<'\n';
		window.draw(ship_1);

		window.display();
	}
	return 0;
}