#include "SFML\Graphics.hpp"
#include <iostream>
#include "Fish.h"

//Compiler Directives
using namespace std;



Fish::Fish()
{	
	sardine = loadAssets.LoadSpriteFromTexture("Assets/", "Fish1", "png");
	trout = loadAssets.LoadSpriteFromTexture("Assets/", "Fish2", "png");
	clownFish = loadAssets.LoadSpriteFromTexture("Assets/", "Fish3", "png");
	water_4 = loadAssets.LoadSpriteFromTexture("Assets/", "Tiles_004", "png");
}

Fish::~Fish(void)
{
}



void Fish::fishSpawner(sf::RenderWindow &window)
{
	//Clock Variables
	sf::Clock fishyClock;

	int fishyWorld[40][50]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height

	//Starting position
	int startI = 0;
	int startJ = 0;
	
	int NoFishes = 0;


	int i, j;
	srand(time(NULL));
	for(i=0; i < worldHeight; i++)
	{
		for(j=0; j < worldWidth; j++)
		{
			if (fishyWorld[i][j] == 04)
			{
				int ransE = rand() %97; //random number of 20 * use a prime number 
				if(ransE <= 2) { //If the number is less than or equal to 2 then spawn in a fish
					ransE += 53; //fish spawn starts at 53
					fishyWorld[i][j] = ransE; //spawn in a fish
				}
			}
		}
	}

	////getting the seconds
	//int sec = (int) fishyClock.getElapsedTime().asSeconds();
	////add a row at every secToAdd seconds
	//int secToAdd = 5;
	////adding a row only if the game started
	//srand(time(NULL));
	//if(sec % secToAdd == secToAdd - 1 && NoFishes < 10)
	//{
	//	int sI; //x co-ordinate
	//	int sJ; //y co-ordinate
	//	do 
	//	{
	//		sI = rand() % 9 + startI;  
	//		sJ = rand() % 13 + startJ;
	//	} 
	//	while(fishyWorld[sI][sJ] != 4); //Checking the co-ordinates until it finds water
	//	if(fishyWorld[i][j] >= 20)
	//	{
	//		int ransF = rand() %3; //3 potential fishes, random number to 3
	//		if(ransF <= 2) //spawn a fish
	//		{ //If the number is less than or equal to 2 then spawn in a fish
	//			ransF += 53; //fish spawn starts at 53
	//			fishyWorld[sI][sJ] = ransF; //spawn in a fish
	//		}
	//		fishyClock.restart();
	//		
	//	}
	//}

}

void Fish::spawnFish(int fishNo, int fishPositionX, int fishPositionY, int startJ, int startI, sf::RenderWindow &window)
{
	sf::Sprite fishType[3] = {sardine, trout, clownFish};
	sf::Sprite fish = fishType[fishNo];
	fish.setPosition((fishPositionX-startJ)*64, (fishPositionY-startI)*64);
	window.draw(fish);
}
