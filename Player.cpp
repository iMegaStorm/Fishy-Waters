#include "Player.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player()
{
	fishNo = 0;
	fishMax = 5;
	srand(time(NULL));
	//gemsNo = 2000;
}

Player::~Player(void)
{
}

bool Player::canMove(int tileType)
{
	//std::cout<<tileType;
	if (tileType <= 20 || tileType == 53 || tileType == 54 || tileType == 55) return true;

	return false;
}

void Player::Inputs(int &gemsNo, sf::Sprite shipType[1], sf::Sprite &shipBlue, sf::Sprite &shipRed, sf::Sprite &shipGreen, sf::Vector2i &posBoat, int &startI, int &startJ, int worldWidth, int worldHeight, int fishyWorld[40][50])
{
		int shipModels;
		int chanceToCatch; //Everytime an input is given then it randomizes 2 numbers, to make it slightly more random
		for (int i = 0; i < 2; ++i) //2 numbers instead of 1 as 1 number just makes it slowly increase and shows no randomness
		{
			chanceToCatch = rand() % 101 + 1; //Chance to catch closest prime number to 100
			//std::cout << chanceToCatch << std::endl;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canMove(fishyWorld[posBoat.y + startI-2][posBoat.x + startJ]))
	{
		//shipType[1].setRotation(180);
		shipRed.setRotation(180);
		shipBlue.setRotation(180);
		shipGreen.setRotation(180);
		horizontalDir = false;
		fishCaughtText = false;
		fishFledText = false;
		if(posBoat.y + startI > 5 && posBoat.y + startI <= worldHeight - 5)
			{
				startI--;
			}
		else
			{
				posBoat.y--;
			}
		if(posBoat.y + startI < +1)
			{
				posBoat.y += 1;
			}
		//std::cout<< "y: "<<posBoat.y + startI<<", x: " <<posBoat.x + startJ<<"\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMove(fishyWorld[posBoat.y + startI][posBoat.x + startJ]))
	{
		//shipType[shipModels].setRotation(0);
		shipRed.setRotation(0);
		shipBlue.setRotation(0);
		shipGreen.setRotation(0);
		horizontalDir = false;
		fishCaughtText = false;
		fishFledText = false;

		if(posBoat.y + startI >= 5 && posBoat.y + startI <= worldHeight - 6)
			{
				startI++;
			}
		else
			{
				posBoat.y++;
			}
		if(posBoat.y + startI > worldHeight-1)
			{
				posBoat.y -= 1;
			}
		//std::cout<< "y: "<<posBoat.y + startI<<", x: " <<posBoat.x + startJ<<"\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMove(fishyWorld[posBoat.y + startI -1][posBoat.x + startJ-1]))
	{
		//shipType[1].setRotation(90);
		shipRed.setRotation(90);
		shipBlue.setRotation(90);
		shipGreen.setRotation(90);
		horizontalDir = true;
		fishCaughtText = false;
		fishFledText = false;

	if(posBoat.x + startJ >= 7 && posBoat.x + startJ <= worldWidth - 7)
		{
			startJ--;
		}
		else
		{
			posBoat.x--;
		}
		if(posBoat.x + startJ < 0)
		{
			posBoat.x += 1;
		}
		//std::cout<< "y: "<<posBoat.y + startI<<", x: " <<posBoat.x + startJ<<"\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMove(fishyWorld[posBoat.y + startI-1][posBoat.x + startJ+1]))
	{
		//shipType[1].setRotation(270);
		shipRed.setRotation(270);
		shipBlue.setRotation(270);
		shipGreen.setRotation(270);
		horizontalDir = true;
		fishCaughtText = false;
		fishFledText = false;

	if(posBoat.x + startJ >= 6 && posBoat.x + startJ <= worldWidth - 8)
		{
			startJ++;
		}
		else
		{
			posBoat.x++;
		}
	if(posBoat.x + startJ >= worldWidth)
		{
			posBoat.x -= 1;
		}
		//std::cout<< "y: "<<posBoat.y +startI<<", x: " <<posBoat.x +startJ +1<<"\n";
	}

	//std::cout<<fishyWorld[posBoat.x + startJ][posBoat.y + startI];

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{		
		if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] && horizontalDir && fishNo < fishMax)
		{	
			if (chanceToCatch > 23 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 53) //If the number returned is higher than the prime number 23 you catch the fish, else the fish flees
			{
				std::cout << "You've rolled: " << chanceToCatch << ", Sardine caught!" << std::endl;
				fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
				fishNo++;
				fishValue += 20;
				std::cout<< "Fish inventory: "<< fishNo << "/" << fishMax << std::endl;
				fishCaughtText = true;
			}
			else if (chanceToCatch < 23 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 53)
			{
				std::cout << "You've rolled: " << chanceToCatch << ", Sardine fled!" << std::endl;
				fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
				fishFledText = true;
			}
			else if (chanceToCatch > 41 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 55) //If the number returned is higher than the prime number 41 you catch the fish, else the fish flees
			{
				std::cout << "You've rolled: " << chanceToCatch << ", Trout caught!" << std::endl;
				fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
				fishNo++;
				fishValue += 50;
				std::cout<< "Fish inventory: "<< fishNo << "/" << fishMax << std::endl;
				fishCaughtText = true;
			}
			else if (chanceToCatch < 41 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 55)
			{	
				std::cout << "You've rolled: " << chanceToCatch << ", Trout fled!" << std::endl;
				fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
				fishFledText = true;
			}
			else if (chanceToCatch > 83 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 54) //If the number returned is higher than the prime number 83 you catch the fish, else the fish flees
			{
				std::cout << "You've rolled: " << chanceToCatch << ", Clownfish caught!" << std::endl;
				fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
				fishNo++;
				fishValue += 100;
				std::cout<< "Fish inventory: "<< fishNo << "/" << fishMax << std::endl;
				fishCaughtText = true;
			}
			else if (chanceToCatch < 83 && fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 54)
				{
					std::cout << "You've rolled: " << chanceToCatch << ", Clownfish fled!" << std::endl;
					fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 04;
					fishFledText = true;
				}
			}
			else if (fishNo >= fishMax)
			{
				std::cout << "Inventory is full!" << std::endl;		
			}

	//Shipwreck Gate 1
		if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 35 && gemsNo >= 100) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 05; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x-1 + startJ] = 03; //The tile down by 1 and then to the left by 1 is set to water 
			gemsNo -= 100; //Removes 100 gems
			std::cout << "You pay the toll! " << gemsNo -100 << " " <<  gemsNo<< std::endl;
		}
		else if (fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 34 && gemsNo >= 100)
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 03; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x+1 + startJ] = 05; //The tile down by 1 and then to the right by 1 is set to water 
			gemsNo -= 100; //Removes 100 gems
			std::cout << "You pay the toll! " << gemsNo -100 << " " <<  gemsNo<< std::endl;
		}
	//Shipwreck Gate 2
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 37 && gemsNo >= 200) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 05; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x-1 + startJ] = 03; //The tile down by 1 and then to the left by 1 is set to water 
			gemsNo -= 200; //Removes 200 gems
			std::cout << "You pay the toll! " << gemsNo << std::endl;
		}
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 36 && gemsNo >= 200) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 03; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x+1 + startJ] = 05; //The tile down by 1 and then to the right by 1 is set to water 
			gemsNo -= 200; //Removes 200 gems
			std::cout << "You pay the toll! " << gemsNo << std::endl;
		}
	//Shipwreck Gate 3
		if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 39 && gemsNo >= 300) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 05; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x-1 + startJ] = 03; //The tile down by 1 and then to the left by 1 is set to water 
			gemsNo -= 300; //Removes 300 gems
			std::cout << "You pay the toll! " << gemsNo -300 << " " <<  gemsNo<< std::endl;
		}
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 38 && gemsNo >= 300) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands 
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 03; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x+1 + startJ] = 05; //The tile down by 1 and then to the right by 1 is set to water 
			gemsNo -= 300; //Removes 300 gems
			std::cout << "You pay the toll! " << gemsNo -300 << " " <<  gemsNo<< std::endl;
		}
	//Shipwreck Gate 4
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 41 && gemsNo >= 400) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 05; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x-1 + startJ] = 03; //The tile down by 1 and then to the left by 1 is set to water  
			gemsNo -= 400; //Removes 400 gems
			std::cout << "You pay the toll! " << gemsNo -400 << " " <<  gemsNo<< std::endl;
		}
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 40 && gemsNo >= 400) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands 
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 03; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x+1 + startJ] = 05; //The tile down by 1 and then to the right by 1 is set to water
			gemsNo -= 400; //Removes 300 gems
			std::cout << "You pay the toll! " << gemsNo -400 << " " <<  gemsNo<< std::endl;
		}
	//Shipwreck Gate 5
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 43 && gemsNo >= 500 ) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 05; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x-1 + startJ] = 03; //The tile down by 1 and then to the left by 1 is set to water 
			gemsNo -= 500; //Removes 500 gems
			std::cout << "You pay the toll! " << gemsNo -500 << " " <<  gemsNo<< std::endl;
		}
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 42  && gemsNo >= 500) //If you have 100 or more gems then you can pay the toll
		{	//I need these 2 if statements as the image takes up 2 tiles, so to clear it depends on where the boat stands 
			fishyWorld[posBoat.y + startI][posBoat.x + startJ] = 03; //Sets the tile below to water
			fishyWorld[posBoat.y + startI][posBoat.x+1 + startJ] = 05; //The tile down by 1 and then to the right by 1 is set to water
			gemsNo -= 500; //Removes 500 gems
			std::cout << "You pay the toll! " << gemsNo -500 << " " << gemsNo<< std::endl;
		}
	}	

	if (fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60)
	{
		std::cout << "Thank you, come again :)" << std::endl;
		gemsNo += fishValue; //Sells the fish and gives you gems
		fishValue = 0; //Resets the current fish value
		fishNo = 0; //Resets the number of fish you're holding
		std::cout<< "Fish inventory: "<< fishNo << "/" << fishMax << std::endl;
	}
	
}
	void Player::Draw(sf::Sprite &shopPanel, sf::Sprite &fishCaught, sf::Sprite &fishFled, sf::Sprite &fullInventory, sf::Sprite &Shipwreck100, sf::Sprite &Shipwreck200, sf::Sprite &Shipwreck300, sf::Sprite &Shipwreck400, sf::Sprite &Shipwreck500, sf::Vector2i &posBoat, int &startI, int &startJ, int fishyWorld[40][50], sf::RenderWindow &window)
	{
		if(fishCaughtText)
		{
			fishCaught.setPosition(posBoat.x*64+32, posBoat.y*64-75); 
			window.draw(fishCaught);
		}
		else if (fishFledText)
		{
			fishFled.setPosition(posBoat.x*64+32, posBoat.y*64-75);
			window.draw(fishFled);
		}
		else if (fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60)
		{
			window.draw(shopPanel);
		}
	//1
		if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 35 || fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 34) //If you have 100 or more gems then you can pay the toll
		{
			Shipwreck100.setPosition(posBoat.x*64+32, posBoat.y*64);
			window.draw(Shipwreck100);
			gate = true;
			//std::cout << "Worked 100" << std::endl;
		}
	//2
		if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 37 || fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 36) //If you have 100 or more gems then you can pay the toll
		{
			Shipwreck200.setPosition(posBoat.x*64+32, posBoat.y*64);
			window.draw(Shipwreck200);
			gate = true;
			//std::cout << "Worked 200" << std::endl;
		}
	//3
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 39 || fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 38) //If you have 100 or more gems then you can pay the toll
		{
			Shipwreck300.setPosition(posBoat.x*64+32, posBoat.y*64);
			window.draw(Shipwreck300);
			gate = true;
			//std::cout << "Worked 300" << std::endl;
		}
	//4
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 41 || fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 40) //If you have 100 or more gems then you can pay the toll
		{
			Shipwreck400.setPosition(posBoat.x*64+32, posBoat.y*64);
			window.draw(Shipwreck400);
			gate = true;
			//std::cout << "Worked 400" << std::endl;
		}
	//5
		else if(fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 43 || fishyWorld[posBoat.y + startI][posBoat.x + startJ] == 42) //If you have 100 or more gems then you can pay the toll
		{
			Shipwreck500.setPosition(posBoat.x*64+32, posBoat.y*64);
			window.draw(Shipwreck500);
			gate = true;
			//std::cout << "Worked 500" << std::endl;
		}
			if (fishNo >= fishMax && !gate)
			{
				fullInventory.setPosition(posBoat.x*64+32, posBoat.y*64);
				window.draw(fullInventory);
			}
			else
			{
			gate = false; //To re-enable the text
			}
			//std::cout << "Gate 1: " << gate1 << " " << "Gate 2: " << gate2 << " " << "Gate 3: " << gate3 << " " << "Gate 4: " << gate4 << " " << "Gate 5: " << gate5 << std::endl;
		//std::cout << "Blockade 4: " << fishyWorld[14][43] << std::endl;
	}
	
	

	//std::cout << "faceRight: " << faceRight << " faceLeft: " << faceLeft << std::endl;
					

		/*std::cout << "Left Blockade 1: " << fishyWorld[12][8] << std::endl;
		std::cout << "Right Blockade 1: " << fishyWorld[12][7] << std::endl << std::endl;

		std::cout << "Left Blockade 2: " << fishyWorld[24][7] << std::endl; 
		std::cout << "Right Blockade 2: " << fishyWorld[24][6] << std::endl << std::endl;

		std::cout << "Left Blockade 3: " << fishyWorld[8][26] << std::endl;
		std::cout << "Right Blockade 3: " << fishyWorld[8][25] << std::endl << std::endl;

		std::cout << "Left Blockade 4: " << fishyWorld[14][44] << std::endl;
		std::cout << "Right Blockade 4: " << fishyWorld[14][43] << std::endl << std::endl;

		std::cout << "Left Blockade 5: " << fishyWorld[38][31]  << std::endl;
		std::cout << "Right Blockade 5: " << fishyWorld[38][30] << std::endl << std::endl;*/
