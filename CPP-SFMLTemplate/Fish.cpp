#include "SFML\Graphics.hpp"
#include <iostream>
#include "Fish.h"
#include <fstream>

//Compiler Directives
using namespace std;

bool fishSpawn = false;

Fish::Fish(sf::RenderWindow &window, sf::Sprite &water_4, sf::Sprite &sardine, sf::Sprite &trout, sf::Sprite &clownFish)
{	
}

Fish::~Fish(void)
{
}

void spawnFish(int fishType, int fishPositionX, int fishPositionY, sf::Sprite fishTypes[3], int startJ, int startI, sf::RenderWindow &window)
{
	sf::Sprite fish = fishTypes[fishType];
	fish.setPosition((fishPositionX-startJ)*64, (fishPositionY-startI)*64);
	window.draw(fish);
}

void fishSpawner(sf::RenderWindow &window, sf::Sprite &water_4, sf::Sprite &sardine, sf::Sprite &trout, sf::Sprite &clownFish)
{
	//Clock Variables
	sf::Clock fishyClock;

	int fishyWorld[40][50]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height

	//Starting position
	int fStartI = 0;
	int fStartJ = 0;
	
	int fNoFishes = 0;
	bool fishSpawn = true;
	std::cout << fishSpawn << std::endl;

	sf::Sprite fishType[3] = {sardine, trout, clownFish};

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
		int noFishes = 0;
		for(i = fStartI; i < fStartI + 9; i++)
		{
			for(j = fStartJ; j < fStartJ + 13; j++)
			{
				if(fishyWorld[i][j] == 55 || fishyWorld[i][j] == 53 || fishyWorld[i][j] == 54)
				{
					water_4.setPosition((j-fStartJ)*64, (i-fStartI)*64);
					window.draw(water_4);
					spawnFish(fishyWorld[i][j] - 53,j,i, fishType, fStartJ, fStartI, window);
					noFishes++;
				} 
			}
		}

	//getting the seconds
	int sec = (int) fishyClock.getElapsedTime().asSeconds();
	//add a row at every secToAdd seconds
	int secToAdd = 3;
	//adding a row only if the game started
	srand(time(NULL));
	if(sec % secToAdd == secToAdd - 1 && fNoFishes < 10)
	{
		int sI; //x co-ordinate
		int sJ; //y co-ordinate
		do 
		{
			sI = rand() % 9 + fStartI;  
			sJ = rand() % 13 + fStartJ;
		} 
		while(fishyWorld[sI][sJ] != 4); //Checking the co-ordinates until it finds water
		if(fishyWorld[i][j] >= 20)
		{
			int ransF = rand() %3; //3 potential fishes, random number to 3
			if(ransF <= 2) //spawn a fish
			{ //If the number is less than or equal to 2 then spawn in a fish
				ransF += 53; //fish spawn starts at 53
				fishyWorld[sI][sJ] = ransF; //spawn in a fish
			}
			fishyClock.restart();
			
		}
	}
}


