#include "SFML\Graphics.hpp"
#include <iostream>

sf::Texture sardine;
sf::Texture trout;
sf::Texture clownfish;



class Fish
{
public:
	int value;
	

	Fish(void);
	~Fish(void);
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

		/*Grouper()
		{
			value = 50;
			grouperText.loadFromFile("GrouperTile.png");
		}*/

		//~Grouper();
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