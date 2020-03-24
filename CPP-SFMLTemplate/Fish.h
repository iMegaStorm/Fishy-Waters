#include "SFML\Graphics.hpp"
#include <iostream>


//sf::Texture sardine;
//sf::Texture trout;
//sf::Texture clownfish;



class Fish
{
public:
	int value;



public:
	Fish(sf::RenderWindow &window, sf::Sprite &water_4, sf::Sprite &sardine, sf::Sprite &trout, sf::Sprite &clownFish);
	~Fish(void);
	void fishSpawner(sf::RenderWindow &window, sf::Sprite &water_4, sf::Sprite &sardine, sf::Sprite &trout, sf::Sprite &clownFish);
	void spawnFish(sf::RenderWindow &window, int fishType, int fishPositionX, int fishPositionY, sf::Sprite fishTypes[3], int startJ, int startI);
};

//class Sardine : public Fish
//{
//	public:
//
//		sf::Sprite sardine;
//		
//
//		Sardine()
//		{		
//			value = 20;
//			//fishText.loadFromFile("fishTile.png");
//		}
//};
//
//
//class Trout : public Fish
//{
//	public:
//
//		sf::Sprite trout;
//
//		/*Grouper()
//		{
//			value = 50;
//			grouperText.loadFromFile("GrouperTile.png");
//		}*/
//
//		//~Grouper();
//};
//
//class Clownfish : public Fish
//{
//	public:
//		
//		sf::Sprite clownfish;
//
//		/*clownfish()
//		{
//			value = 80;
//			clownfish.loadFromFile("barTile.png");
//		}*/
//
//
//};