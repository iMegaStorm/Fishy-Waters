#include "Enemies.h"


Enemies::Enemies(void)
{
	currentHealth = 5;
	maxHealth = 5;
	startPos.x = 03;
	startPos.y = 20;
}


Enemies::~Enemies(void)
{
}

bool Enemies::canMove(int tileType)
{
	if (tileType <= 20 || tileType == 53 || tileType == 54 || tileType == 55 || tileType == 56 || tileType == 57) return true;

	return false;
}

void Enemies::EnemyInput(sf::Vector2i &posEnemy, sf::Vector2i posBoat, sf::Sprite &pirateShip,int &startI, int &startJ,  int worldWidth, int worldHeight, int fishyWorld[40][50])
{
	//std::cout << posEnemy.x << " " << posEnemy.y << std::endl;
	//std::cout << posBoat.x +startJ<< " " << posBoat.y +startI << std::endl;
	//std::cout << "Pirates health: " << currentHealth << "/" << maxHealth << std::endl;

	posBoat.x += startJ;
	posBoat.y += startI;

	if (posBoat.x > startPos.x -6 && posBoat.x < startPos.x +6)
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

	if (posBoat.y > startPos.y -6 && posBoat.y < startPos.y +6)
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