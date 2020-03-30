//updated on 30/03/2020

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
Player player;
Fish fish;

//Game Screen Variables
	//Assigns a value for each screen
const int GAME_MENU_SCREEN = 0; //Main game screen
const int INSTRUCTIONS_MENU_SCREEN = 1; //Instructions Menu screen
const int LEVEL_1_SCREEN = 2; // Level 1 of the game
const int LEVEL_2_SCREEN = 3;
const int GAME_OVER_SCREEN = 4; //Game Over screen
int CURRENT_SCREEN = GAME_MENU_SCREEN; //Using current screen in order to switch to another screen


const int RED_SHIP = 1;
const int BLUE_SHIP = 2;
const int GREEN_SHIP = 3;
int PLAYER_SHIP = RED_SHIP;

Vector2i mouseCursorLocation(0,0);

 
void spawnTiles(int tileType, int tilePositionX, int tilePositionY, Sprite tileTypes[44], int startJ, int startI)
{
	Sprite terrian = tileTypes[tileType];
	terrian.setPosition((tilePositionX-startJ)*64, (tilePositionY-startI)*64);
	window.draw(terrian);
}

void gameAssets(Sprite &water_0, Sprite &water_1, Sprite &water_2, Sprite &water_3, Sprite &water_4, Sprite &water_5, Sprite &water_6, Sprite &water_7,
Sprite &water_8, Sprite &water_9, Sprite &water_10, Sprite &water_11, Sprite &water_12, Sprite &water_13, Sprite &water_14, Sprite &water_15,
Sprite &water_16, Sprite &water_17, Sprite &water_18, Sprite &water_19, Sprite &water_20, Sprite &grass_21, Sprite &grass_22, Sprite &grass_23, 
Sprite &grass_24,  Sprite &grass_25, Sprite &grass_26, Sprite &grass_27, Sprite &grass_28, Sprite &grass_29, Sprite &grass_30, Sprite &grass_31,
Sprite &grass_32, Sprite &grass_33, Sprite &shipRed, Sprite &shipBlue, Sprite &shipGreen, Sprite &pirateShip, Sprite &blockade, Sprite &sardine, Sprite &trout, Sprite &clownFish, Sprite &shop,
Sprite &blockadeLeft, Sprite &blockadeRight, Sprite &gems, Sprite &shopPanel, Sprite &Shipwreck100,  Sprite &Shipwreck200, Sprite &Shipwreck300, Sprite &Shipwreck400, Sprite &Shipwreck500, Sprite &fishCaught, Sprite &fishFled, Sprite &fullInventory, Sprite &playButton, Sprite &exitButton)
{
	//Environment Tiles
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

	//Player sprites
	shipRed = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipRed", "png");
	shipRed.setOrigin(64.0/2, 64.0/2);

	shipBlue  = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipBlue", "png");
	shipBlue.setOrigin(64.0/2, 64.0/2);


	shipGreen = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipGreen", "png");
	shipGreen.setOrigin(64.0/2, 64.0/2);
	
	//Enemy sprites
	pirateShip = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "PirateShip", "png");

	//Blockade sprites 
	blockadeRight = loadAssets.LoadSpriteFromTexture("Assets/", "BlockadeRight", "png");
	blockadeLeft = loadAssets.LoadSpriteFromTexture("Assets/", "BlockadeLeft", "png");

	//Fish sprites
	sardine = loadAssets.LoadSpriteFromTexture("Assets/", "Fish1", "png");
	trout = loadAssets.LoadSpriteFromTexture("Assets/", "Fish2", "png");
	clownFish = loadAssets.LoadSpriteFromTexture("Assets/", "Fish3", "png");

	shop = loadAssets.LoadSpriteFromTexture("Assets/", "Shop", "png");

	//UI and text
	gems = loadAssets.LoadSpriteFromTexture("Assets/", "Gem", "png");
	shopPanel = loadAssets.LoadSpriteFromTexture("Assets/", "ShopPanel", "png");
	shopPanel.setPosition(1, 38);
	Shipwreck100  = loadAssets.LoadSpriteFromTexture("Assets/", "Shipwreck100", "png");
	Shipwreck100.setOrigin(323/2, 29/2);
	Shipwreck200  = loadAssets.LoadSpriteFromTexture("Assets/", "Shipwreck200", "png");
	Shipwreck200.setOrigin(324/2, 29/2);
	Shipwreck300  = loadAssets.LoadSpriteFromTexture("Assets/", "Shipwreck300", "png");
	Shipwreck300.setOrigin(323/2, 29/2);
	Shipwreck400  = loadAssets.LoadSpriteFromTexture("Assets/", "Shipwreck400", "png");
	Shipwreck400.setOrigin(324/2, 29/2);
	Shipwreck500  = loadAssets.LoadSpriteFromTexture("Assets/", "Shipwreck500", "png");
	Shipwreck500.setOrigin(324/2, 29/2);
	fullInventory = loadAssets.LoadSpriteFromTexture("Assets/", "FullInventory", "png");
	fullInventory.setOrigin(52/2, 19/2);
	fishCaught  = loadAssets.LoadSpriteFromTexture("Assets/", "FishCaught", "png");
	fishCaught.setOrigin(133/2, 24/2);
	fishFled  = loadAssets.LoadSpriteFromTexture("Assets/", "FishFled", "png");
	fishFled.setOrigin(99/2, 19/2);
	playButton = loadAssets.LoadSpriteFromTexture("Assets/", "PlayButton", "png");
	playButton.setOrigin(89/2,40/2);
	playButton.setPosition(400, 250);
	exitButton = loadAssets.LoadSpriteFromTexture("Assets/", "ExitButton", "png");
	exitButton.setOrigin(82/2, 40/2);
	exitButton.setPosition(405, 350);

}

int main()
{
//Local Variables
	//Event Variables
	Event event;

	Sprite water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, shipRed, shipBlue, shipGreen, pirateShip, blockade, sardine, trout, clownFish, shop, blockadeRight, blockadeLeft, gems, shopPanel, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, fishCaught, fishFled, fullInventory, playButton, exitButton;
	gameAssets(water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, shipRed, shipBlue, shipGreen, pirateShip, blockade, sardine, trout, clownFish, shop, blockadeRight, blockadeLeft, gems, shopPanel,Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, fishCaught, fishFled, fullInventory, playButton, exitButton);

	int fishyWorld[40][50]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height

	//Starting position
	int startI = 0;
	int startJ = 0;

	//Clock Variables
	sf::Clock fishyClock;
	
	Vector2i posBoat (0, 3); //Setting position of the boat
	
	window.setFramerateLimit(60);

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
				int ransE = rand() %37; //random number of 37 as its a prime number
				if(ransE <= 2) { //If the number is less than or equal to 10 then spawn in a fish
					ransE += 53; //fish spawn starts at 53
					fishyWorld[i][j] = ransE; //spawn in a fish
				}
			}
		}
	}
	
	Sprite tileType[44] = 
	{
	water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, 
	water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, 
	grass_31, grass_32, grass_33, blockadeRight, blockadeLeft, blockadeRight, blockadeLeft,blockadeRight, blockadeLeft,blockadeRight, blockadeLeft,blockadeRight, blockadeLeft	
	};

	Sprite shipType[3] = {shipRed, shipBlue, shipGreen};
	//shipType[2] = shipType[player.shipModels];

	Sprite fishType[3] = {sardine, trout, clownFish};

	while (window.isOpen()) //The Game Window Loop
	{
		cout << fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] << endl;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if(event.type == Event::KeyPressed && CURRENT_SCREEN == LEVEL_1_SCREEN) 
			{
				player.Inputs(player.gemsNo, shipType, shipBlue, shipRed, shipGreen, posBoat, startI, startJ, worldWidth, worldHeight, fishyWorld); //Calls the method from the class player
			}
			else if (event.type == Event::MouseMoved) //Mouse Movement
			{
				mouseCursorLocation = Mouse::getPosition(window);
			}
			else if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if ((CURRENT_SCREEN == GAME_MENU_SCREEN && mouseCursorLocation.x > playButton.getPosition().x - playButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (playButton.getPosition().x + playButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > playButton.getPosition().y - playButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (playButton.getPosition().y + playButton.getGlobalBounds().height/2)))
						{
							CURRENT_SCREEN = INSTRUCTIONS_MENU_SCREEN; //Changes the current screen if you click on the play button
						}
					else if ((CURRENT_SCREEN == GAME_MENU_SCREEN && mouseCursorLocation.x > exitButton.getPosition().x - exitButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (exitButton.getPosition().x + exitButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > exitButton.getPosition().y - exitButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (exitButton.getPosition().y + exitButton.getGlobalBounds().height/2)))
						{
							window.close(); //Closes the window if you click on the exit button
						}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipRed.getPosition().x - shipRed.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipRed.getPosition().x + shipRed.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipRed.getPosition().y - shipRed.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipRed.getPosition().y + shipRed.getGlobalBounds().height/2)))
					{					
						PLAYER_SHIP = RED_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipRed.setRotation(270);
					}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipBlue.getPosition().x - shipBlue.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipBlue.getPosition().x + shipBlue.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipBlue.getPosition().y - shipBlue.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipBlue.getPosition().y + shipBlue.getGlobalBounds().height/2)))
					{
						PLAYER_SHIP = BLUE_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipBlue.setRotation(270);
					}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipGreen.getPosition().x - shipGreen.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipGreen.getPosition().x + shipGreen.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipGreen.getPosition().y - shipGreen.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipGreen.getPosition().y + shipGreen.getGlobalBounds().height/2)))
					{
						PLAYER_SHIP = GREEN_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipGreen.setRotation(270);
					}
				}
			}

		}
		window.clear(sf::Color(100,100,100));

		if (CURRENT_SCREEN == GAME_MENU_SCREEN)
		{
			window.draw(playButton);
			window.draw(exitButton);


		}
		else if (CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN)
		{
			shipRed.setPosition(200, 300);
			shipBlue.setPosition(300, 300);
			shipGreen.setPosition(400, 300);
			shipRed.setScale(2,2);
			shipBlue.setScale(2,2);
			shipGreen.setScale(2,2);
			window.draw(shipRed);
			window.draw(shipBlue);
			window.draw(shipGreen);
		}
		else if (CURRENT_SCREEN == LEVEL_1_SCREEN)
		{

		int noFishes = 0;
		for(i = startI; i < startI + 9; i++)
		{
			for(j = startJ; j < startJ + 13; j++)
			{
				if(fishyWorld[i][j] == 55 || fishyWorld[i][j] == 53 || fishyWorld[i][j] == 54)
				{
					//fish.fishSpawner(window);
					//fish.spawnFish(-53, j, i, startJ, startI, window);
				} 
				if (fishyWorld[i][j] == 53)
				{
					sardine.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(sardine);
					noFishes++;
				}
				else if (fishyWorld[i][j] == 54)
				{
					trout.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(trout);
					noFishes++;
				}
				else if (fishyWorld[i][j] == 55)
				{
					clownFish.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(clownFish);
					noFishes++;
				}
				else if (fishyWorld[i][j] == 60)
				{
					shop.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(shop);
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
				else if ((fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] == 03 || fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] == 05) &&  (fishyWorld[38][30] == 03 || fishyWorld[38][31] == 05))
				{
					CURRENT_SCREEN = LEVEL_2_SCREEN;
				}
				else 
				{
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI); 
				}
			}
		}

	//getting the seconds
	int sec = (int) fishyClock.getElapsedTime().asSeconds();
	//add a row at every secToAdd seconds
	int secToAdd = 5;
	//adding a row only if the game started
	srand(time(NULL));
	if(sec % secToAdd == secToAdd - 1 && noFishes < 10)
	{
		int sI; //x co-ordinate
		int sJ; //y co-ordinate
		do 
		{
			sI = rand() % 9 + startI;  
			sJ = rand() % 13 + startJ;
		} 
		while(fishyWorld[sI][sJ] != 4); //Checking the co-ordinates until it finds water
		if(fishyWorld[i][j] >= 20)
		{
			int ransF = rand() %3; //3 potential fishes, random number to 3
			if(ransF <= 2) //spawn a fish
			{ //If the number is less than or equal to 2 then spawn in a fish
				ransF += 53; //fish spawn starts at 53
				fishyWorld[sI][sJ] = ransF; //spawn in a fish
			}
			fishyClock.restart();
		}
	}

		window.draw(gems);
		Arial.setString("Gems: " + to_string(player.gemsNo));
		window.draw(Arial);
		
			if (PLAYER_SHIP == RED_SHIP)
			{
				shipRed.setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipRed.setScale(1,1);
				window.draw(shipRed);
			}
			else if (PLAYER_SHIP == BLUE_SHIP)
			{
				shipBlue.setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipBlue.setScale(1,1);
				window.draw(shipBlue);
			}
			else if (PLAYER_SHIP == GREEN_SHIP)
			{
				shipGreen.setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipGreen.setScale(1,1);
				window.draw(shipGreen);
			}
			player.Draw(shopPanel, fishCaught, fishFled, fullInventory, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, posBoat, startI, startJ, fishyWorld, window);
		}
		else if (CURRENT_SCREEN == GAME_OVER_SCREEN)
		{
			
		}
		window.display();
	}
	return 0;
}