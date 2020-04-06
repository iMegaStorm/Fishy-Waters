#include "Enemies.h"

Player playerShip;
CannonBall cannonFire;

Enemies::Enemies(void)
{
	enemyCurrentHealth = enemyMaxHealth = 5;
	startPos.x = 03;
	startPos.y = 20; 
}


Enemies::~Enemies(void)
{
}

bool Enemies::canMove(int tileType)
{
	if (tileType == 04 || tileType == 90 || tileType == 91 || tileType == 92 || tileType == 93 || tileType == 94) return true;

	return false;
}

//void Enemies::Shoot(sf::Vector2i &posBoat, int &CurrentHealth, int startI, int startJ, sf::Sprite currentShip)
//{
//	
//		if (abs(position.x-posBoat.x) == 5 && abs(position.y-posBoat.y) == 19)
//		{
//			std::cout << "Can Shoot" << " X: " << abs(position.x-posBoat.x) <<  " Y: " << abs(position.y-posBoat.y) << std::endl;
//			//std::cout << abs(position.x) << " " << " X: " << abs(position.x-posBoat.x) <<  " Y: " << abs(position.y-posBoat.y) << std::endl;
//			ShootBullets(posBoat);
//			currentCannonBall--;
//		}
//		else if (abs(position.x-posBoat.x) == 2 && abs(position.y-posBoat.y) == 2)
//		{
//			std::cout << "Can Shoot" << " X: " << abs(position.x-posBoat.x) <<  " Y: " << abs(position.y-posBoat.y) << std::endl;
//			//std::cout << abs(position.y) << " " << abs(posBoat.y) << std::endl;
//			ShootBullets(posBoat);
//			currentCannonBall--;
//		}
//		else
//		{
//			std::cout << "Cant shoot" << " X: " << abs(position.x-posBoat.x -startJ) <<  " Y: " << abs(position.y-posBoat.y -startI) << std::endl;
//		}
//	}
		
void Enemies::ShootBullets(sf::Vector2i playerPosition)
{
//Local Variables

//Main "ShootBullets()"
	CannonBall* Bullets = new CannonBall();
	Bullets -> Init("Assets/ships/cannonBall.png", position , playerPosition);
	cannonBall.push_back(Bullets);
	//std::cout << position.x << " " << position.y << std::endl;
}

void Enemies::EnemyInput(sf::Vector2i &posEnemy, sf::Vector2i posBoat, sf::Sprite &pirateShip, int &startI, int &startJ,  int worldWidth, int worldHeight, int fishyWorld[40][50])
{
	//std::cout << posEnemy.x << " " << posEnemy.y << std::endl;
	//std::cout << posBoat.x +startJ<< " " << posBoat.y +startI << std::endl;
	
	
	posBoat.x += startJ;
	posBoat.y += startI;

	if (posBoat.x > startPos.x -6 && posBoat.x < startPos.x +5 && enemyCurrentHealth > 0)
	{
		if(posEnemy.x > posBoat.x && canMove(fishyWorld[posEnemy.y +startI-1][posEnemy.x +startJ-1]))
		{
			//pirateShip.setRotation(90);
			fishyWorld[posEnemy.y][posEnemy.x] = 04;
			fishyWorld[posEnemy.y][--posEnemy.x] = 99;			
		}
		else if(posEnemy.x < posBoat.x && canMove(fishyWorld[posEnemy.y +startI-1][posEnemy.x +startJ-1]))
		{
			//pirateShip.setRotation(270);
			fishyWorld[posEnemy.y][posEnemy.x] = 04;
			fishyWorld[posEnemy.y][++posEnemy.x] = 99;
		}
	}
	else if (posBoat.y > startPos.y -6 && posBoat.y < startPos.y +5 && enemyCurrentHealth > 0)
	{
		if(posEnemy.y > posBoat.y && canMove(fishyWorld[posEnemy.y +startI-2][posEnemy.x +startJ]))
		{
			//pirateShip.setRotation(180);
			fishyWorld[posEnemy.y][posEnemy.x] = 04;
			fishyWorld[--posEnemy.y][posEnemy.x] = 99;
		}
		else if(posEnemy.y < posBoat.y && canMove(fishyWorld[posEnemy.y +startI][posEnemy.x +startJ]))
		{
			//pirateShip.setRotation(0);
			fishyWorld[posEnemy.y][posEnemy.x] = 04;
			fishyWorld[++posEnemy.y][posEnemy.x] = 99;
		}
	}
	//std::cout << "Pirates health: " << enemyCurrentHealth << "/" << enemyMaxHealth << std::endl;
	//std::cout << enemyShipSunk << std::endl;
}

void Enemies::Draw(sf::Sprite &pirateShip,  sf::Sprite &pirateShipDamaged, sf::Sprite &pirateShipDead, sf::Vector2i posEnemy, int startJ, int startI, int fishyWorld[40][50], sf::RenderWindow &window)
{
	if (enemyCurrentHealth > 2)
	{
		pirateShip.setPosition((posEnemy.x -startJ)*64+32, (posEnemy.y -startI)*64+32);
		window.draw(pirateShip);
	}
	else if (enemyCurrentHealth <= 2 && enemyCurrentHealth > 0)
	{
		pirateShipDamaged.setPosition((posEnemy.x -startJ)*64+32, (posEnemy.y -startI)*64+32);
		window.draw(pirateShipDamaged);
	}
	else if (enemyCurrentHealth <= 0)
	{
		pirateShipDead.setPosition((posEnemy.x -startJ)*64+32, (posEnemy.y -startI)*64+32);
		window.draw(pirateShipDead);

	}
}


/*if (fishyWorld[posEnemy.y + pStartI-1][posEnemy.x + pStartJ-1] == 99  > posBoat.x)
		{
			pirateShip.setRotation(90);
		
			if(posEnemy.x + pStartJ >= 7 && posEnemy.x + pStartJ <= worldWidth - 7)
			{
				pStartJ--;
			}
			else
			{
				posEnemy.x--;
			}
			if(posEnemy.x + pStartJ < 0)
			{
				posEnemy.x += 1;
			}
		}
		else if (fishyWorld[posEnemy.y + pStartI-1][posEnemy.x + pStartJ+1] == 99 < posBoat.x)
		{
		
			pirateShip.setRotation(270);
			if(posEnemy.x + pStartJ >= 6 && posEnemy.x + pStartJ <= worldWidth - 8)
			{
				pStartJ++;
			}
			else
			{
				posEnemy.x++;
			}
		if(posEnemy.x + pStartJ >= worldWidth)
			{
				posEnemy.x -= 1;
			}
		}
		else if (fishyWorld[posEnemy.y + pStartI-2][posEnemy.x + pStartJ] == 99 > posBoat.y-1)
		{
			pirateShip.setRotation(180);
			
			if(posEnemy.y + pStartI > 5 && posEnemy.y + pStartI <= worldHeight - 5)
				{
					pStartI--;
				}
			else
				{
					posEnemy.y--;
				}
			if(posEnemy.y + pStartI < +1)
				{
					posEnemy.y += 1;
				}
		}
		else if(fishyWorld[posEnemy.y + pStartI][posEnemy.x + pStartJ] == 99 < posBoat.y-1)
		{
			pirateShip.setRotation(0);
			if(posEnemy.y +pStartI >= 5 && posEnemy.y +pStartI <= worldHeight - 6)
				{
					pStartI++;
				}
			else
				{
					posEnemy.y++;
				}
			if(posEnemy.y + pStartI > worldHeight-1)
				{
					posEnemy.y -= 1;
				}
		}*/