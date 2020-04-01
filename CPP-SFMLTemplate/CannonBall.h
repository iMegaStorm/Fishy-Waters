//The Enemy Bullet Class Declaration...
#pragma once
//Header Files
#include <SFML/Graphics.hpp>

class CannonBall
{
//...

//Main Class "Bullet()"
public:
	CannonBall();
	~CannonBall();
	void Init(std::string TextureName, sf::Vector2i &playerPosition, sf::Vector2i &piratePosition);
	void Update(float Speed);
	sf::Sprite GetSprite();
	sf::Vector2f BulletPosition;
	sf::Vector2f BulletPositionTarget;

private:
	sf::Texture BulletTexture;
	sf::Sprite BulletSprite;
	float CannonBallSpeed;
};