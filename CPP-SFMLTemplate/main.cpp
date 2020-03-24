//updated on 19/02/2020

#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include "loadAssets.h"
#include "Player.h"
#include "Fish.h"


//Compiler Directives
using namespace std;

RenderWindow window(VideoMode(832, 576), "Fishy Waters"); // 13 squares wide, 9 square high

LoadAssets loadAssets;

Fish fish;

bool canMove(int tileType)
{
	cout<<tileType;
	if (tileType <= 20 || tileType == 35) return true;

	return false;
}

void spawnTiles(int tileType, int tilePositionX, int tilePositionY, Sprite tileTypes[36], int startJ, int startI)
{
	Sprite terrian = tileTypes[tileType];
	terrian.setPosition((tilePositionX-startJ)*64, (tilePositionY-startI)*64);
	window.draw(terrian);
}

void spawnFish(int fishType, int fishPositionX, int fishPositionY, Sprite fishTypes[3], int startJ, int startI)
{
	Sprite fish = fishTypes[fishType];
	fish.setPosition((fishPositionX-startJ)*64, (fishPositionY-startI)*64);
	window.draw(fish);
}

void inputs (Sprite &ship_1, Vector2i &posBoat, int &startI, int &startJ, int worldWidth, int worldHeight, int fishyWorld[40][50])
{
	bool W = false, S = false, A = false, D = false;

	if (Keyboard::isKeyPressed(Keyboard::W) && canMove(fishyWorld[posBoat.y + startI-2][posBoat.x + startJ]))
	{
		ship_1.setRotation(180);
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
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && canMove(fishyWorld[posBoat.y + startI][posBoat.x + startJ]))
	{
		ship_1.setRotation(0);
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
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && canMove(fishyWorld[posBoat.y + startI -1][posBoat.x + startJ-1]))
	{
		ship_1.setRotation(90);
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
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && canMove(fishyWorld[posBoat.y + startI - 1][posBoat.x + startJ+1]))
	{
		ship_1.setRotation(270);
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
	}
	//cout<<fishyWorld[posBoat.x + startJ][posBoat.y + startI];
	cout<< "x: "<<posBoat.x<<" y: " <<posBoat.y<<"\n";
}

void gameAssets(Sprite &water_0, Sprite &water_1, Sprite &water_2, Sprite &water_3, Sprite &water_4, Sprite &water_5, Sprite &water_6, Sprite &water_7,
Sprite &water_8, Sprite &water_9, Sprite &water_10, Sprite &water_11, Sprite &water_12, Sprite &water_13, Sprite &water_14, Sprite &water_15,
Sprite &water_16, Sprite &water_17, Sprite &water_18, Sprite &water_19, Sprite &water_20, Sprite &grass_21, Sprite &grass_22, Sprite &grass_23, 
Sprite &grass_24,  Sprite &grass_25, Sprite &grass_26, Sprite &grass_27, Sprite &grass_28, Sprite &grass_29, Sprite &grass_30, Sprite &grass_31,
Sprite &grass_32, Sprite &grass_33, Sprite &ship_1, Sprite &pirateShip, Sprite &blockade, Sprite &sardine, Sprite &trout, Sprite &clownFish, Sprite &shop,
Sprite &blockadeLeft, Sprite &blockadeRight, Sprite &gems)
{
	water_0 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_000", "png");
	water_1 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_001", "png");
	water_2 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_002", "png");
	water_3 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_003", "png");
	water_4 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_004", "png");
	water_5 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_005", "png");
	water_6 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_006", "png");
	water_7 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_007", "png");
	water_8 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_008", "png");
	water_9 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_009", "png");
	water_10 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_010", "png");
	water_11 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_011", "png");
	water_12 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_012", "png");
	water_13 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_013", "png");
	water_14 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_014", "png");
	water_15 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_015", "png");
	water_16 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_016", "png");
	water_17 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_017", "png");
	water_18 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_018", "png");
	water_19 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_019", "png");
	water_20 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_020", "png");
	grass_21 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_021", "png");
	grass_22 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_022", "png");
	grass_23 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_023", "png");
	grass_24 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_024", "png");
	grass_25 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_025", "png");
	grass_26 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_026", "png");
	grass_27 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_027", "png");
	grass_28 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_028", "png");
	grass_29 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_029", "png");
	grass_30 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_030", "png");
	grass_31 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_031", "png");
	grass_32 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_032", "png");
	grass_33 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_033", "png");

	ship_1 = loadAssets.LoadSpriteFromTexture("Assets/", "ship_1", "png");
	ship_1.setOrigin(64.0/2, 64.0/2);
	ship_1.setRotation(270);

	pirateShip = loadAssets.LoadSpriteFromTexture("Assets/", "PirateShip", "png");

	blockade = loadAssets.LoadSpriteFromTexture("Assets/", "Blockade", "png");
	blockadeRight = loadAssets.LoadSpriteFromTexture("Assets/", "BlockadeRight", "png");
	blockadeLeft = loadAssets.LoadSpriteFromTexture("Assets/", "BlockadeLeft", "png");

	sardine = loadAssets.LoadSpriteFromTexture("Assets/", "Fish1", "png");
	trout = loadAssets.LoadSpriteFromTexture("Assets/", "Fish2", "png");
	clownFish = loadAssets.LoadSpriteFromTexture("Assets/", "Fish3", "png");

	shop = loadAssets.LoadSpriteFromTexture("Assets/", "Shop", "png");

	gems = loadAssets.LoadSpriteFromTexture("Assets/", "Gem", "png");
	
}

int main()
{
//Local Variables
	//Event Variables
	Event event;


	Sprite water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, ship_1, pirateShip, blockade, sardine, trout, clownFish, shop, blockadeRight, blockadeLeft, gems;
	gameAssets(water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, ship_1, pirateShip, blockade, sardine, trout, clownFish, shop, blockadeRight, blockadeLeft, gems);

	//RectangleShape fishyBoat;
	//fishyBoat.setSize(Vector2f(64, 64));
	//fishyBoat.setFillColor(Color(0, 0, 0));

	int fishyWorld[40][50]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height

	//Starting position
	int startI = 0;
	int startJ = 0;
	
	Vector2i posBoat (0, 3); //Setting position of the boat
	
	window.setFramerateLimit(60);

	int gemsNo = 0;

	//Font Variable
	sf::Font ArialFont;
	sf::Text text;
	float ArialCurrentScaleX = 0.8f,ArialCurrentScaleY = 0.8f;
	sf::Vector2f ArialLocation(35,0);

	ArialFont.loadFromFile("Fonts/Arial/arial.ttf");

	sf::Text Arial;
	Arial.setScale(sf::Vector2f(ArialCurrentScaleX,ArialCurrentScaleY));
	Arial.setFont(ArialFont);
	Arial.setPosition(ArialLocation.x, ArialLocation.y);
	Arial.setString("Gems: ");


	
	ifstream fishyMap("Assets/Map.txt"); //Reading map

	int i, j;
	srand(time(NULL));
	for(i=0; i < worldHeight; i++)
	{
		for(j=0; j < worldWidth; j++)
		{
			fishyMap>>fishyWorld[i][j];
			if (fishyWorld[i][j] == 04)
			{
				int ransE = rand() %97; //random number of 20 * use a prime number 
				if(ransE <= 2) { //If the number is less than or equal to 2 then spawn in a fish
					ransE += 53; //fish spawn starts at 53
					fishyWorld[i][j] = ransE; //spawn in a fish
				}
			}
		}
	}
	
	Sprite tileType[36] = 
	{
	water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9,
	water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18,
	water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, 
	grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, blockadeRight, blockadeLeft	
	};

	Sprite fishType[3] = {sardine, trout, clownFish};

	while (window.isOpen()) //The Game Window Loop
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if(event.type == Event::KeyPressed) 
			{
				inputs(ship_1, posBoat, startI, startJ, worldWidth, worldHeight, fishyWorld);
			}
		}
		window.clear(sf::Color(100,100,100));

		int noFishes = 0;
		for(i = startI; i < startI + 9; i++)
		{
			for(j = startJ; j < startJ + 13; j++)
			{
				if(fishyWorld[i][j] == 55 || fishyWorld[i][j] == 53 || fishyWorld[i][j] == 54)
				{
					water_4.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_4);
					spawnFish(fishyWorld[i][j] - 53,j,i, fishType, startJ, startI);
					noFishes++;
				} 
				else if (fishyWorld[i][j] == 60)
				{
					grass_25.setPosition((j-startJ)*64, (i-startI)*64);
					shop.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(grass_25);
					window.draw(shop);
				}
				else if (fishyWorld[i][j] == 34)
				{
					water_3.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_3);
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI);
				}
				else if (fishyWorld[i][j] == 35)
				{
					water_5.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_5);
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI);
				}

				else if (fishyWorld[i][j] == 99)
				{
					water_4.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(water_4);
					pirateShip.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(pirateShip);
				}
				else if (fishyWorld[i][j] >= 21) 
				{
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI); 
				} 
				else 
				{
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI); 
				}
			}
		}

		window.draw(gems);
		Arial.setString("Gems: " + to_string(gemsNo));
		window.draw(Arial);
		ship_1.setPosition(posBoat.x*64+32, posBoat.y*64-32);
		//cout<<posBoat.y<<'\n';
		window.draw(ship_1);
		window.display();
	}
	return 0;
}