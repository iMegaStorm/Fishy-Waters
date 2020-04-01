#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Fish
{
public:
	int value;
private:
	//sf::Sprite sardine, tuna, trout, clownFish, pufferFish, water_4;

public:
	Fish(	);
	~Fish(void);
	

	void fishSpawner(sf::RenderWindow &window);
	void spawnFish(sf::Sprite &sardine, sf::Sprite &tuna, sf::Sprite &trout, sf::Sprite &clownFish, sf::Sprite &pufferFish, int fishNo, int fishPositionX, int fishPositionY, int startJ, int startI, sf::RenderWindow &window);
	
};

class Sardine : public Fish
{
	public:

		sf::Sprite sardine;
		

		Sardine()
		{		
			value = 20;
			//fishText.loadFromFile("fishTile.png");
		}
};


class Trout : public Fish
{
	public:

		sf::Sprite trout;

		/*trout()
		{
			value = 50;
			grouperText.loadFromFile("GrouperTile.png");
		}*/

		//~trout();
};

class Clownfish : public Fish
{
	public:
		
		sf::Sprite clownfish;

		/*clownfish()
		{
			value = 80;
			clownfish.loadFromFile("barTile.png");
		}*/


};