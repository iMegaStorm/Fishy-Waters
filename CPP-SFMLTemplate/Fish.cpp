#include "SFML\Graphics.hpp"
#include <iostream>
#include "Fish.h"

//Compiler Directives
using namespace std;



Fish::Fish()
{	

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
	
	//int NoFishes = 0;


	int i, j;
	//srand(time(NULL));
	//for(i=0; i < worldHeight; i++)
	//{
	//	for(j=0; j < worldWidth; j++)
	//	{
	//		if (fishyWorld[i][j] == 04)
	//		{
	//			//int ransE = rand() %97; //random number of 20 * use a prime number 
	//			//if(ransE <= 2) 
	//			//{ //If the number is less than or equal to 2 then spawn in a fish
	//			//	ransE += 53; //fish spawn starts at 53
	//			//	fishyWorld[i][j] = ransE; //spawn in a fish
	//			//}
	//		}
	//	}
	//}
}

void Fish::spawnFish(sf::Sprite &sardine, sf::Sprite &tuna, sf::Sprite &trout, sf::Sprite &clownFish, sf::Sprite &pufferFish, int fishNo, int fishPositionX, int fishPositionY, int startJ, int startI, sf::RenderWindow &window)
{
	sf::Sprite fishType[5] = {sardine, tuna, trout, clownFish, pufferFish};
	sf::Sprite fish = fishType[fishNo];
	fish.setPosition((fishPositionX-startJ)*64, (fishPositionY-startI)*64);
	//window.draw(fish);
}
