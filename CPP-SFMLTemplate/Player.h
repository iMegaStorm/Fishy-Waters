#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Player
{
public:
	float X, Y;
	int gemsNo;
	int fishNo;
	int fishMax;
	int fishInventory;
	int fishValue;
	bool horizontalDir; //Facing left or right direction
	bool fishCaughtText;
	bool fishFledText;

public:

	Player();
	~Player();
	bool canMove(int tileType);
	void Inputs (int &gemsNo, sf::Sprite &ship_1, sf::Vector2i &posBoat, int &startI, int &startJ, int worldWidth, int worldHeight, int fishyWorld[40][50]);
	void Player::Draw(sf::Sprite &shopPanel, sf::Sprite &fishCaught, sf::Sprite &fishFled, sf::Sprite &fullInventory, sf::Sprite &toll, sf::Vector2i &posBoat, int &startI, int &startJ, int fishyWorld[40][50], sf::RenderWindow &window);
};

