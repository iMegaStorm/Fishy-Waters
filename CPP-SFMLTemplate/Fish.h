#include "SFML\Graphics.hpp"
#include <iostream>
#include "loadAssets.h"





class Fish
{
public:
	int value;
private:
	LoadAssets loadAssets;
	sf::Sprite sardine, trout, clownFish, water_4;

public:
	Fish(	);
	~Fish(void);
	

	void fishSpawner(sf::RenderWindow &window);
	void spawnFish(int fishType, int fishPositionX, int fishPositionY, int startJ, int startI, sf::RenderWindow &window);
	
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