#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Player
{
public:
	int gemsNo; //Currency
	int fishNo; //How many fishes you can hold
	int fishMax; //Maximum amount of fish held
	int fishValue; //Holds a value of the fishes so you can sell them
	bool horizontalDir; //Facing left or right direction
	bool fishCaughtText; //To display the fish has been caught sprite
	bool fishFledText; //To display the fish has fled sprite
	bool gate; //Checks to see if the player is above the shipwreck and then disables the full inventory text
	int gateValue;
	bool gate1, gate2,gate3, gate4, gate5;
	
	//sf::Sprite shipType

public:

	Player();
	~Player();
	bool canMove(int tileType);
	void PlayerModel(sf::Sprite &shipRed, sf::Sprite shipBlue);
	void Inputs (int &gemsNo, sf::Sprite shipType[1], sf::Sprite &shipBlue, sf::Sprite &shipRed, sf::Sprite &shipGreen, sf::Vector2i &posBoat, int &startI, int &startJ, int worldWidth, int worldHeight, int fishyWorld[40][50]);
	void Player::Draw(sf::Sprite &shopPanel, sf::Sprite &fishCaught, sf::Sprite &fishFled, sf::Sprite &fullInventory, sf::Sprite &Shipwreck100, sf::Sprite &Shipwreck200, sf::Sprite &Shipwreck300, sf::Sprite &Shipwreck400, sf::Sprite &Shipwreck500, sf::Vector2i &posBoat, int &startI, int &startJ, int fishyWorld[40][50], sf::RenderWindow &window);
};

