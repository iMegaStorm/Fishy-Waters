#include "SFML\Graphics.hpp"
#include <iostream>
#include "Fish.h"
#include<fstream>

//Compiler Directives
using namespace std;



Fish::Fish()
{	
	
}

Fish::~Fish(void)
{
}

void Fish::spawnFish(int fishNo, int fishPositionX, int fishPositionY, sf::Sprite fishType[5], int startJ, int startI, sf::RenderWindow &window)
{
	sf::Sprite fish = fishType[fishNo];
	fish.setPosition((fishPositionX-startJ)*64, (fishPositionY-startI)*64);
	window.draw(fish);
}
