#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemies
{
public:
	int enemyCurrentHealth;
	int enemyMaxHealth;
	int currentCannonBall;
	int maxCannonBall;
	bool enemyShipSunk;
	sf::Vector2i startPos;


public:
	Enemies(void);
	~Enemies(void);
	bool canMove(int tileType);
	void EnemyInput(sf::Vector2i &posEnemy, sf::Vector2i posBoat, sf::Sprite &pirateShip, int &startI, int &startJ,  int worldWidth, int worldHeight, int fishyWorld[40][50]);
	void Enemies::Draw(sf::Sprite &pirateShip, sf::Sprite &pirateShipDamaged, sf::Sprite &pirateShipDead, sf::Vector2i posEnemy, int startJ, int startI, int fishyWorld[40][50], sf::RenderWindow &window);
};

