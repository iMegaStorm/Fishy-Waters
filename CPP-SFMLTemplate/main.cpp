//updated on 06/04/2020

#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include "loadAssets.h"
#include "Player.h"
#include "Fish.h"
#include "Enemies.h"
#include "CannonBall.h"
#include <vector>

//Compiler Directives
using namespace std;

RenderWindow window(VideoMode(832, 576), "Fishy Waters",Style::Close); // 13 squares wide, 9 square high

LoadAssets loadAssets;
Player player;
Enemies enemyShip;
Fish fish;

vector<CannonBall*> EnemyBullets;

//Game Screen Variables
	//Assigns a value for each screen
const int GAME_MENU_SCREEN = 0; //Main game screen
const int INSTRUCTIONS_MENU_SCREEN = 1; //Instructions Menu screen
const int LEVEL_1_SCREEN = 2; // Level 1 of the game
const int LEVEL_2_SCREEN = 3; // Level 2 of the game
const int GAME_OVER_SCREEN = 4; //Game Over screen
int CURRENT_SCREEN = GAME_MENU_SCREEN; //Using current screen in order to switch to another screen


const int RED_SHIP = 1;
const int BLUE_SHIP = 2;
const int GREEN_SHIP = 3;
int PLAYER_SHIP = RED_SHIP;

Vector2i mouseCursorLocation(0,0);
 
void spawnTiles(int tileType, int tilePositionX, int tilePositionY, Sprite tileTypes[50], int startJ, int startI)
{
	Sprite terrian = tileTypes[tileType];
	terrian.setPosition((tilePositionX-startJ)*64, (tilePositionY-startI)*64);
	window.draw(terrian);
}

void gameAssets(Sprite &water_0, Sprite &water_1, Sprite &water_2, Sprite &water_3, Sprite &water_4, Sprite &water_5, Sprite &water_6, Sprite &water_7,
Sprite &water_8, Sprite &water_9, Sprite &water_10, Sprite &water_11, Sprite &water_12, Sprite &water_13, Sprite &water_14, Sprite &water_15,
Sprite &water_16, Sprite &water_17, Sprite &water_18, Sprite &water_19, Sprite &water_20, Sprite &grass_21, Sprite &grass_22, Sprite &grass_23, 
Sprite &grass_24,  Sprite &grass_25, Sprite &grass_26, Sprite &grass_27, Sprite &grass_28, Sprite &grass_29, Sprite &grass_30, Sprite &grass_31,
Sprite &grass_32, Sprite &grass_33, Sprite &bush_45, Sprite &tree_46, Sprite &tree_47, Sprite &tree_48, Sprite &tree_49, Sprite &rock_50, Sprite &shipRed, Sprite &shipRedDamaged, Sprite &shipRedDead, Sprite &shipBlue, Sprite &shipBlueDamaged, Sprite &shipBlueDead, Sprite &shipGreen, Sprite &shipGreenDamaged, Sprite &shipGreenDead, Sprite &pirateShip, Sprite &pirateShipDamaged, Sprite &pirateShipDead, Sprite &cannonBall, Sprite &gameScreenBackground, Sprite &instructionsMenuBackground, Sprite &fishyWorldTitle, Sprite &sardine, Sprite &tuna, Sprite &pufferFish, Sprite &trout, Sprite &clownFish, Sprite &shop,
Sprite &blockadeLeft, Sprite &blockadeRight, Sprite &gems, Sprite &shopPanel, Sprite &buyButton, Sprite &buy5Button, Sprite &exitShopButton, Sprite &sellFishesButton, Sprite &Shipwreck100,  Sprite &Shipwreck200, Sprite &Shipwreck300, Sprite &Shipwreck400, Sprite &Shipwreck500, Sprite &fishCaught, Sprite &fishFled, Sprite &fullInventory, Sprite &playButton, Sprite &exitButton, Sprite &level2Background, Sprite &gameOverBackground, Sprite &restartButton)
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
	bush_45 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_045", "png");
	tree_46 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_046", "png");
	tree_47 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_047", "png");
	tree_48 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_048", "png");
	tree_49 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_049", "png");
	rock_50 = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Tiles_050", "png");
	shop = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "Shop", "png");
	blockadeRight = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "BlockadeRight", "png");
	blockadeLeft = loadAssets.LoadSpriteFromTexture("Assets/Tiles/", "BlockadeLeft", "png");

	//CannonBall sprite
	cannonBall = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "cannonBall", "png");
	cannonBall.setOrigin(5, 5);

	//Player sprites
	shipRed = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipRed", "png");
	shipRed.setOrigin(64.0/2, 64.0/2);
	shipRedDamaged = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipRedDamaged", "png");
	shipRedDamaged.setOrigin(64.0/2, 64.0/2);
	shipRedDead = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipRedDead", "png");
	shipRedDead.setOrigin(64.0/2, 64.0/2);

	shipBlue = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipBlue", "png");
	shipBlue.setOrigin(64.0/2, 64.0/2);
	shipBlueDamaged = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipBlueDamaged", "png");
	shipBlueDamaged.setOrigin(64.0/2, 64.0/2);
	shipBlueDead = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipBlueDead", "png");
	shipBlueDead.setOrigin(64.0/2, 64.0/2);

	shipGreen = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipGreen", "png");
	shipGreen.setOrigin(64.0/2, 64.0/2);
	shipGreenDamaged = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipGreenDamaged", "png");
	shipGreenDamaged.setOrigin(64.0/2, 64.0/2);
	shipGreenDead = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "shipGreenDead", "png");
	shipGreenDead.setOrigin(64.0/2, 64.0/2);

	//Enemy sprites
	pirateShip = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "PirateShip", "png");
	pirateShip.setOrigin(64/2, 64/2);
	pirateShipDamaged  = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "PirateShipDamaged", "png");
	pirateShipDamaged.setOrigin(64/2, 64/2);
	pirateShipDead = loadAssets.LoadSpriteFromTexture("Assets/Ships/", "PirateShipDead", "png");
	pirateShipDead.setOrigin(64/2, 64/2);

	//Fish sprites
	sardine = loadAssets.LoadSpriteFromTexture("Assets/Fishes/", "Sardine", "png");
	tuna = loadAssets.LoadSpriteFromTexture("Assets/Fishes/", "Tuna", "png");
	pufferFish = loadAssets.LoadSpriteFromTexture("Assets/Fishes/", "Pufferfish", "png");
	trout = loadAssets.LoadSpriteFromTexture("Assets/Fishes/", "Trout", "png");
	clownFish = loadAssets.LoadSpriteFromTexture("Assets/Fishes/", "ClownFish", "png");



	//UI and text
	gameScreenBackground = loadAssets.LoadSpriteFromTexture("Assets/UI/", "gameScreenBackground", "jpg");
	gameScreenBackground.setOrigin(1366/2, 768/2);
	gameScreenBackground.setPosition(832/2, 576/2);
	fishyWorldTitle = loadAssets.LoadSpriteFromTexture("Assets/UI/", "FishyWorldTitle", "png");
	fishyWorldTitle.setOrigin(457/2, 75/2);
	fishyWorldTitle.setPosition(832/2, 376/2);
	instructionsMenuBackground = loadAssets.LoadSpriteFromTexture("Assets/UI/", "InstructionsMenuBackground", "jpg");
	instructionsMenuBackground.setOrigin(2560/2, 1600/2);
	instructionsMenuBackground.setPosition(832/2, 576/2);
	instructionsMenuBackground.setScale(0.4,0.4);
	gameOverBackground = loadAssets.LoadSpriteFromTexture("Assets/UI/", "GameOverBackground", "png");
	level2Background = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Level2Background", "png");
	gems = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Gem", "png");
	shopPanel = loadAssets.LoadSpriteFromTexture("Assets/UI/", "ShopPanel", "png");
	shopPanel.setPosition(1, 38);
	exitShopButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "ExitShopButton", "png");
	exitShopButton.setOrigin(38/2, 36/2);
	exitShopButton.setPosition(364, 38);
	sellFishesButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "SellFishesButton", "png");
	sellFishesButton.setOrigin(38/2, 36/2);
	sellFishesButton.setPosition(310, 480);
	buyButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "BuyButton", "png");
	buyButton.setOrigin(132/2, 68/2);
	buyButton.setPosition(92, 313);
	buy5Button = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Buy5Button", "png");
	buy5Button.setOrigin(132/2, 68/2);
	buy5Button.setPosition(225, 313);
	Shipwreck100  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Shipwreck100", "png");
	Shipwreck100.setOrigin(323/2, 29/2);
	Shipwreck200  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Shipwreck200", "png");
	Shipwreck200.setOrigin(324/2, 29/2);
	Shipwreck300  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Shipwreck300", "png");
	Shipwreck300.setOrigin(323/2, 29/2);
	Shipwreck400  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Shipwreck400", "png");
	Shipwreck400.setOrigin(324/2, 29/2);
	Shipwreck500  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "Shipwreck500", "png");
	Shipwreck500.setOrigin(324/2, 29/2);
	fullInventory = loadAssets.LoadSpriteFromTexture("Assets/UI/", "FullInventory", "png");
	fullInventory.setOrigin(52/2, 19/2);
	fishCaught  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "FishCaught", "png");
	fishCaught.setOrigin(133/2, 24/2);
	fishFled  = loadAssets.LoadSpriteFromTexture("Assets/UI/", "FishFled", "png");
	fishFled.setOrigin(99/2, 19/2);
	playButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "PlayButton", "png");
	playButton.setOrigin(173/2,66/2);
	playButton.setPosition(400, 400);
	restartButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "RestartButton", "png");
	restartButton.setOrigin(183/2, 66/2);
	restartButton.setPosition(325, 380);
	exitButton = loadAssets.LoadSpriteFromTexture("Assets/UI/", "ExitButton", "png");
	exitButton.setOrigin(146/2, 66/2);
	exitButton.setPosition(400, 500);

}

int main()
{
//Local Variables
	//Event Variables
	Event event;

	Sprite water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, bush_45, tree_46, tree_47, tree_48, tree_49, rock_50, shipRed, shipRedDamaged, shipRedDead, shipBlue, shipBlueDamaged, shipBlueDead, shipGreen, shipGreenDamaged, shipGreenDead, pirateShip, pirateShipDamaged, pirateShipDead, cannonBall , gameScreenBackground, instructionsMenuBackground, fishyWorldTitle, sardine, tuna, pufferFish, trout, clownFish, shop, blockadeRight, blockadeLeft, gems, shopPanel, buyButton, buy5Button, exitShopButton, sellFishesButton, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, fishCaught, fishFled, fullInventory, playButton, exitButton, level2Background, gameOverBackground, restartButton;
	gameAssets(water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, grass_31, grass_32, grass_33, bush_45, tree_46, tree_47, tree_48, tree_49, rock_50, shipRed, shipRedDamaged, shipRedDead, shipBlue, shipBlueDamaged, shipBlueDead, shipGreen, shipGreenDamaged, shipGreenDead, pirateShip,  pirateShipDamaged, pirateShipDead, cannonBall, gameScreenBackground, instructionsMenuBackground, fishyWorldTitle, sardine, tuna, pufferFish, trout, clownFish, shop, blockadeRight, blockadeLeft, gems, shopPanel, buyButton, buy5Button, exitShopButton, sellFishesButton, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, fishCaught, fishFled, fullInventory, playButton, exitButton, level2Background, gameOverBackground, restartButton);

	int fishyWorld[40][50]; //Declaring my array
	int worldWidth = 50; //world Width
	int worldHeight = 40; //World Height
	Vector2i posBoat  (0, 2); //Setting position of the boat
	Vector2i posEnemy (0, 3); //Setting position of the pirate ship

	//Starting position
	int startJ = 0;
	int startI = 0;

	//Clock Variables
	sf::Clock fishyClock;
	
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

	sf::Text sellPrice;
	sellPrice.setScale(sf::Vector2f(ArialCurrentScaleX,ArialCurrentScaleY));
	sellPrice.setFont(ArialFont);
	sellPrice.setColor(Color(0,0,0));
	sellPrice.setPosition(185, 466);

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
					if(ransE <= 4) { //If the number is less than or equal to 4 then spawn in a fish
						ransE += 90; //fish spawn starts at 53
						fishyWorld[i][j] = ransE; //spawn in a fish
					}
				}
				else if (fishyWorld[i][j] == 99)
				{
					posEnemy.x = j;
					posEnemy.y = i;
				}
			}
		}

	
	Sprite tileType[50] = {water_0, water_1, water_2, water_3, water_4, water_5, water_6, water_7, water_8, water_9, water_10, water_11, water_12, water_13, water_14, water_15, 
	water_16, water_17, water_18, water_19, water_20, grass_21, grass_22, grass_23, grass_24, grass_25, grass_26, grass_27, grass_28, grass_29, grass_30, 
	grass_31, grass_32, grass_33, blockadeRight, blockadeLeft, blockadeRight, blockadeLeft,blockadeRight, blockadeLeft,blockadeRight, blockadeLeft,blockadeRight, blockadeLeft,
	bush_45, tree_46, tree_47, tree_48, tree_49, rock_50};

	Sprite shipType[9] = {shipRed, shipBlue, shipGreen, shipRedDamaged, shipBlueDamaged, shipGreenDamaged, shipRedDead, shipBlueDead, shipGreenDead};
	Sprite fishType[5] = {sardine, tuna, trout, clownFish, pufferFish};

	while (window.isOpen()) //The Game Window Loop
	{
		
		//cout << fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] << endl;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if(event.type == Event::KeyPressed && CURRENT_SCREEN == LEVEL_1_SCREEN) 
			{
				player.Inputs(player.gemsNo, shipType, posBoat, startI, startJ, worldWidth, worldHeight, fishyWorld); //Calls the method from the class player
				enemyShip.EnemyInput(posEnemy, posBoat, pirateShip, startI, startJ, worldWidth, worldHeight, fishyWorld);
				//enemyShip.Shoot(posBoat, player.currentHealth, startI, startJ, pirateShip);
				player.Shoot(posEnemy, enemyShip.enemyCurrentHealth, shipType[0]);
				//cout << "Pirate Health from main: "<< enemyShip.enemyCurrentHealth << endl;
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
					else if ((CURRENT_SCREEN == GAME_MENU_SCREEN || CURRENT_SCREEN == GAME_OVER_SCREEN && mouseCursorLocation.x > exitButton.getPosition().x - exitButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (exitButton.getPosition().x + exitButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > exitButton.getPosition().y - exitButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (exitButton.getPosition().y + exitButton.getGlobalBounds().height/2)))
						{
							window.close(); //Closes the window if you click on the exit button
						}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipRed.getPosition().x - shipRed.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipRed.getPosition().x + shipRed.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipRed.getPosition().y - shipRed.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipRed.getPosition().y + shipRed.getGlobalBounds().height/2)))
					{					
						PLAYER_SHIP = RED_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipRed.setRotation(0);
					}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipBlue.getPosition().x - shipBlue.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipBlue.getPosition().x + shipBlue.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipBlue.getPosition().y - shipBlue.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipBlue.getPosition().y + shipBlue.getGlobalBounds().height/2)))
					{
						PLAYER_SHIP = BLUE_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipBlue.setRotation(0);
					}
					else if ((CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN && mouseCursorLocation.x > shipGreen.getPosition().x - shipGreen.getGlobalBounds().width/2) && (mouseCursorLocation.x < (shipGreen.getPosition().x + shipGreen.getGlobalBounds().width/2)) && (mouseCursorLocation.y > shipGreen.getPosition().y - shipGreen.getGlobalBounds().height/2) && (mouseCursorLocation.y < (shipGreen.getPosition().y + shipGreen.getGlobalBounds().height/2)))
					{
						PLAYER_SHIP = GREEN_SHIP;
						CURRENT_SCREEN = LEVEL_1_SCREEN;
						shipGreen.setRotation(0);
					}
					else if ((CURRENT_SCREEN == LEVEL_1_SCREEN && fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60 && player.currentCannonBall < player.maxCannonBall && player.gemsNo >= 50 && mouseCursorLocation.x > buyButton.getPosition().x - buyButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (buyButton.getPosition().x + buyButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > buyButton.getPosition().y - buyButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (buyButton.getPosition().y + buyButton.getGlobalBounds().height/2)))
					{					
						player.currentCannonBall++;
						player.gemsNo -= 50;
						cout << "1 Cannonball bought" << endl;
					}
					else if ((CURRENT_SCREEN == LEVEL_1_SCREEN && fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60 && player.gemsNo >= 250 && mouseCursorLocation.x > buy5Button.getPosition().x - buy5Button.getGlobalBounds().width/2) && (mouseCursorLocation.x < (buy5Button.getPosition().x + buy5Button.getGlobalBounds().width/2)) && (mouseCursorLocation.y > buy5Button.getPosition().y - buy5Button.getGlobalBounds().height/2) && (mouseCursorLocation.y < (buy5Button.getPosition().y + buy5Button.getGlobalBounds().height/2)))
					{					
						if (player.currentCannonBall == 0 || player.currentCannonBall == 5)
						{
							player.currentCannonBall += 5;
							player.gemsNo -= 250;
							cout << "5 Cannonball bought" << endl;
						}
						else 
						{
							cout << "Not enough inventory space" << endl;
						}
					}
					else if ((CURRENT_SCREEN == LEVEL_1_SCREEN && fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60 && mouseCursorLocation.x > exitShopButton.getPosition().x - exitShopButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (exitShopButton.getPosition().x + exitShopButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > exitShopButton.getPosition().y - exitShopButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (exitShopButton.getPosition().y + exitShopButton.getGlobalBounds().height/2)))
					{					
						player.shopActive  = false;
					}
					else if ((CURRENT_SCREEN == GAME_OVER_SCREEN && mouseCursorLocation.x > restartButton.getPosition().x - restartButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (restartButton.getPosition().x + restartButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > restartButton.getPosition().y - restartButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (restartButton.getPosition().y + restartButton.getGlobalBounds().height/2)))
					{
						CURRENT_SCREEN = INSTRUCTIONS_MENU_SCREEN;
						enemyShip.enemyCurrentHealth = 5;
						player.currentHealth = 5;
						player.gemsNo = 2000;
						player.fishNo = 0;
						startJ = 0;
						startI = 0;		
						posBoat.x = 0;
						posBoat.y = 2;

						//Reseting blockades
						if (fishyWorld[12][7]==03 && fishyWorld[12][8]==05)
						{
						fishyWorld[12][7]=34;
						fishyWorld[12][8]=35;
						}
						if(fishyWorld[24][6]==03 && fishyWorld[24][7]==05)
						{
						fishyWorld[24][6]=36;
						fishyWorld[24][7]=37;
						}
						if(fishyWorld[8][25]==03 && fishyWorld[8][26]==05)
						{
						fishyWorld[8][25]=38;
						fishyWorld[8][26]=39;
						}
						if(fishyWorld[14][43]==03 && fishyWorld[14][44]==05)
						{
						fishyWorld[14][43]=40;
						fishyWorld[14][44]=41;
						}
						if(fishyWorld[38][30]==03 && fishyWorld[38][31]==05)
						{
						fishyWorld[38][30]=42;
						fishyWorld[38][31]=43;
						}
					}
					else if ((CURRENT_SCREEN == LEVEL_1_SCREEN && fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60 && mouseCursorLocation.x > sellFishesButton.getPosition().x - sellFishesButton.getGlobalBounds().width/2) && (mouseCursorLocation.x < (sellFishesButton.getPosition().x + sellFishesButton.getGlobalBounds().width/2)) && (mouseCursorLocation.y > sellFishesButton.getPosition().y - sellFishesButton.getGlobalBounds().height/2) && (mouseCursorLocation.y < (sellFishesButton.getPosition().y + sellFishesButton.getGlobalBounds().height/2)))
					{					
						player.gemsNo += player.fishValue; //Sells the fish and gives you gems
						player.fishValue = 0; //Resets the current fish value
						player.fishNo = 0; //Resets the number of fish you're holding
					}
				}
			}
		}
		window.clear(sf::Color(100,100,100));

		if (CURRENT_SCREEN == GAME_MENU_SCREEN)
		{
			window.draw(gameScreenBackground);
			window.draw(fishyWorldTitle);
			window.draw(playButton);
			window.draw(exitButton);
		}
		else if (CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN)
		{
			window.draw(instructionsMenuBackground);
			shipRed.setPosition(336, 500);
			shipBlue.setPosition(416, 500);
			shipGreen.setPosition(496, 500);
			shipRed.setRotation(0);
			shipBlue.setRotation(0);
			shipGreen.setRotation(0);
			shipRed.setScale(1.5,1.5);
			shipBlue.setScale(1.5,1.5);
			shipGreen.setScale(1.5,1.5);
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
				if (fishyWorld[i][j] >= 90 && fishyWorld[i][j] <= 97)
				{
					fish.spawnFish(fishyWorld[i][j] -90, j, i, fishType, startJ, startI, window);
					noFishes++;
				}
				else if (fishyWorld[i][j] == 60)
				{
					shop.setPosition((j-startJ)*64, (i-startI)*64);
					window.draw(shop);
				}

				else if (fishyWorld[i][j] == 99)
				{
					enemyShip.Draw(pirateShip, pirateShipDamaged,pirateShipDead, posEnemy, startJ, startI, fishyWorld, window);
				}
				else if (fishyWorld[i][j] < 53) 
				{
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI); 
				} 
			}
		}
		if ((fishyWorld[posBoat.y-1 +startI][posBoat.x + startJ] == 03 || fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] == 05) &&  (fishyWorld[38][30] == 03 || fishyWorld[38][31] == 05))
		{
			CURRENT_SCREEN = LEVEL_2_SCREEN;
		}
		//cout << fishyWorld[posBoat.y-1 + startI][posBoat.x + startJ] << endl;
		//cout << fishyWorld[38][30] << " " << fishyWorld[38][31] << endl;

		for (CannonBall *Bullet : player.cannonBall)
		{
			Sprite cannonBallShot;
			cannonBallShot = Bullet->GetSprite();
			cannonBallShot.setPosition((Bullet->BulletPosition.x -startJ)*64, (Bullet->BulletPosition.y -startI)*64);
			window.draw(cannonBallShot);
			

				if(Bullet->BulletPosition.x < Bullet->BulletPositionTarget.x)
				{
					Bullet->BulletPosition.x += 1;
				}
				else if(Bullet->BulletPosition.x > Bullet->BulletPositionTarget.x)
				{
					Bullet->BulletPosition.x -= 1;
				}
				else if(Bullet->BulletPosition.y < Bullet->BulletPositionTarget.y)
				{
					Bullet->BulletPosition.y += 1;
				}
				else if(Bullet->BulletPosition.y > Bullet->BulletPositionTarget.y)
				{
					Bullet->BulletPosition.y -= 1;
				}

				if ((Bullet->BulletPosition.x == Bullet->BulletPositionTarget.x) && (Bullet->BulletPosition.y == Bullet->BulletPositionTarget.y))
				{
						if(rand() % 10 + 1 >= 4)
						{
							enemyShip.enemyCurrentHealth -=1;
							Bullet->BulletPosition.x = Bullet->BulletPositionTarget.x -9999999999999999999;
							Bullet->BulletPosition.y = Bullet->BulletPositionTarget.y -9999999999999999999;
							cout << "You've hit the Pirate ship! "  << enemyShip.enemyCurrentHealth << "/" << enemyShip.enemyMaxHealth << endl;
						}
						else
						{
							Bullet->BulletPosition.x = Bullet->BulletPositionTarget.x -9999999999999999999;
							Bullet->BulletPosition.y = Bullet->BulletPositionTarget.y -9999999999999999999;
							cout << "You've missed the Pirate ship! " << enemyShip.enemyCurrentHealth << "/" << enemyShip.enemyMaxHealth << endl;
						}
						if(rand() % 10 + 1 >= 5)
						{
							player.currentHealth -=1;
							Bullet->BulletPosition.x = Bullet->BulletPositionTarget.x -9999999999999999999;
							Bullet->BulletPosition.y = Bullet->BulletPositionTarget.y -9999999999999999999;
							
							cout << "The Pirate ship lands a hit on you " << player.currentHealth << "/" << player.maxHealth << endl;
						}
						else
						{
							Bullet->BulletPosition.x = Bullet->BulletPositionTarget.x -9999999999999999999;
							Bullet->BulletPosition.y = Bullet->BulletPositionTarget.y -9999999999999999999;
							
							cout << "The Pirate ship misses! " << player.currentHealth << "/" << player.maxHealth << endl;
						}
				}

				if(player.currentHealth <= 0)
				{
					CURRENT_SCREEN = GAME_OVER_SCREEN;
				}

					/*for (i = 0; i<EnemyBullets.size(); i++)
					{
						cout << "True" << endl;
						CannonBall* Bullets = EnemyBullets[i];
						if(rand() % 10 + 1 >= 4)
						{
							enemyShip.enemyCurrentHealth-=1;
							cout << "Hit" << endl;
						}
						else
						{
							cout << "Miss" << endl;
						}
						EnemyBullets.erase(EnemyBullets.begin()+ i);
						delete(Bullets);
						break;
					}*/
					
				
			//cout << Bullet->BulletPosition.x << " " << Bullet->BulletPosition.y << endl;
		}

	//getting the seconds
	int sec = (int) fishyClock.getElapsedTime().asSeconds();
	//add a row at every secToAdd seconds
	int secToAdd = 4;
	//adding a row only if the game started
	srand(time(NULL));
	if(sec % secToAdd == secToAdd - 1 && noFishes < 15)
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
			int ransF = rand() %5; //3 potential fishes, random number to 3
			if(ransF <= 2) //spawn a fish
			{ //If the number is less than or equal to 2 then spawn in a fish
				ransF += 90; //fish spawn starts at 53
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
				shipType[0].setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipType[0].setScale(1,1);
			}
			else if (PLAYER_SHIP == BLUE_SHIP)
			{
				shipType[1].setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipType[1].setScale(1,1);
			}
			else if (PLAYER_SHIP == GREEN_SHIP)
			{
				shipType[2].setPosition(posBoat.x*64+32, posBoat.y*64-32);
				shipType[2].setScale(1,1);
			}
			
			player.Draw(shipType, shopPanel, buyButton, buy5Button, exitShopButton, sellFishesButton, fishCaught, fishFled, fullInventory, PLAYER_SHIP, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, posBoat, startI, startJ, fishyWorld, window);

			if(fishyWorld[posBoat.y-2 + startI][posBoat.x + startJ] == 60 && player.shopActive)
			{
				sellPrice.setString(to_string(player.fishValue));
				window.draw(sellPrice);
			}
		}
		else if (CURRENT_SCREEN == LEVEL_2_SCREEN)
		{
			window.draw(level2Background);
		}
		else if (CURRENT_SCREEN == GAME_OVER_SCREEN)
		{
			shipRed.setRotation(0);
			shipBlue.setRotation(0);
			shipGreen.setRotation(0);

			int noFishes = 0;
			for(i = startI; i < startI + 9; i++)
			{
				for(j = startJ; j < startJ + 13; j++)
				{
					if (fishyWorld[i][j] >= 90 && fishyWorld[i][j] <= 97)
					{
						fish.spawnFish(fishyWorld[i][j] -90, j, i, fishType, startJ, startI, window);
						noFishes++;
					}
					else if (fishyWorld[i][j] == 60)
					{
						shop.setPosition((j-startJ)*64, (i-startI)*64);
						window.draw(shop);
					}

				else if (fishyWorld[i][j] == 99)
				{
					enemyShip.Draw(pirateShip, pirateShipDamaged,pirateShipDead, posEnemy, startJ, startI, fishyWorld, window);
				}
				else if (fishyWorld[i][j] < 53) 
				{
					spawnTiles(fishyWorld[i][j], j,i, tileType, startJ, startI); 
				} 
			}
		}
		player.Draw(shipType, shopPanel, buyButton, buy5Button, exitShopButton, sellFishesButton, fishCaught, fishFled, fullInventory, PLAYER_SHIP, Shipwreck100, Shipwreck200, Shipwreck300, Shipwreck400, Shipwreck500, posBoat, startI, startJ, fishyWorld, window);
			
			exitButton.setPosition(525, 380);
			window.draw(gems);
			window.draw(Arial);
			window.draw(gameOverBackground);
			window.draw(restartButton);
			window.draw(exitButton);
		}
		window.display();
	}
	return 0;
}

