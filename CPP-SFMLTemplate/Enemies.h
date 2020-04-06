#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "CannonBall.h"
#include <vector>

class Enemies
{
public:
	int enemyCurrentHealth;
	int enemyMaxHealth;
	int currentCannonBall;
	int maxCannonBall;
	sf::Vector2i startPos;
	std::vector<CannonBall*> cannonBall;
	sf::Vector2i position;


public:
	Enemies(void);
	~Enemies(void);
	bool canMove(int tileType);
	void Shoot(sf::Vector2i &posBoat, int &CurrentHealth, sf::Sprite currentShip);
	void ShootBullets(sf::Vector2i playerPosition);
	void EnemyInput(sf::Vector2i &posEnemy, sf::Vector2i posBoat, sf::Sprite &pirateShip, int &startI, int &startJ,  int worldWidth, int worldHeight, int fishyWorld[40][50]);
	void Draw(sf::Sprite &pirateShip, sf::Sprite &pirateShipDamaged, sf::Sprite &pirateShipDead, sf::Vector2i posEnemy, int startJ, int startI, int fishyWorld[40][50], sf::RenderWindow &window);
};

