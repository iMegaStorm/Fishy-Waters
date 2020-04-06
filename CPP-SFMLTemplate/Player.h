#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Enemies.h"
#include "CannonBall.h"
#include <vector>

class Player
{
public:
	int currentHealth;
	int maxHealth;
	int currentCannonBall;
	int maxCannonBall;
	int cannonBallValue;
	int gemsNo; //Currency
	int fishNo; //How many fishes you can hold
	int fishMax; //Maximum amount of fish held
	int fishValue; //Holds a value of the fishes so you can sell them
	bool horizontalDir; //Facing left or right direction
	bool fishCaughtText; //To display the fish has been caught sprite
	bool fishFledText; //To display the fish has fled sprite
	bool gate; //Checks to see if the player is above the shipwreck and then disables the full inventory text
	bool shopActive; //Draws the shop if this bool is active




	//The "Enemy Bullets" Variables...
	std::vector<CannonBall*> cannonBall;
	sf::Vector2i position;

public:

	Player();
	~Player();
	bool canMove(int tileType);
	void Shoot(sf::Vector2i &posEnemy, int &enemyCurrentHealth, sf::Sprite currentShip);
	void ShootBullets(sf::Vector2i piratePosition);
	void Inputs (int &gemsNo, sf::Sprite shipType[6], sf::Vector2i &posBoat, int &pStartI, int &pStartJ, int worldWidth, int worldHeight, int fishyWorld[40][50]);
	void Draw(sf::Sprite shipType[6], sf::Sprite &shopPanel, sf::Sprite &buyButton, sf::Sprite &buy5Button, sf::Sprite &exitShopButton, sf::Sprite &sellFishesButton, sf::Sprite &fishCaught, sf::Sprite &fishFled, sf::Sprite &fullInventory, int PLAYER_SHIP, sf::Sprite &Shipwreck100, sf::Sprite &Shipwreck200, sf::Sprite &Shipwreck300, sf::Sprite &Shipwreck400, sf::Sprite &Shipwreck500, sf::Vector2i &posBoat, int &startI, int &startJ, int fishyWorld[40][50], sf::RenderWindow &window);
};

