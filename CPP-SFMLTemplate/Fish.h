#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Fish
{
public:
	int value;

public:
	Fish(	);
	~Fish(void);

	void spawnFish(int fishNo, int fishPositionX, int fishPositionY, sf::Sprite fishType[5], int startJ, int startI, sf::RenderWindow &window);
	
};



class Sardine : public Fish
{
	public:
		Sardine()
		{		
			value += 20;
		}
};

class Tuna : public Fish
{
	public:
		Tuna()
		{
			value = 30;
		}
};


class Trout : public Fish
{
	public:
		Trout()
		{
			value = 50;
		}
};

class Clownfish : public Fish
{
	public:
		Clownfish()
		{
			value = 75;
		}
		
};

class Pufferfish : public Fish
{
	public:
		Pufferfish()
		{
			value = 100;
		}		
};