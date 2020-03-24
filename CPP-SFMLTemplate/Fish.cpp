#include "SFML\Graphics.hpp"
#include <iostream>
#include "Fish.h"
#include <fstream>

//Compiler Directives
using namespace std;

Fish::Fish()
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

	ifstream fishyMap("Assets/Map.txt"); //Reading map

	int i, j;
	srand(time(NULL));
	for(i=0; i < worldHeight; i++)
	{
		for(j=0; j < worldWidth; j++)
		{
			fishyMap>>fishyWorld[i][j];
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

					//getting the seconds
					int sec = (int) fishyClock.getElapsedTime().asSeconds();
					//add a row at every secToAdd seconds
					int secToAdd = 15;
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


Fish::~Fish(void)
{
}
