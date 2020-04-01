#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemies
{
public:
	int currentHealth;
	int maxHealth;
	int currentCannonBall;
	int maxCannonBall;
	sf::Vector2i startPos;


public:
	Enemies(void);
	~Enemies(void);
	bool canMove(int tileType);
	void EnemyInput(sf::Vector2i &posEnemy, sf::Vector2i posBoat, sf::Sprite &pirateShip,int &startI, int &startJ,  int worldWidth, int worldHeight, int fishyWorld[40][50]);
};

