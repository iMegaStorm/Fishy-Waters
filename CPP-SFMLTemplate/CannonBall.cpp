//The Enemy Bullet Class Implementation...

//Header Files
#include "CannonBall.h"

CannonBall::CannonBall()
{
//Local Variables

//Main "CannonBall()"

}

CannonBall::~CannonBall()
{
//Local Variables

//Main "~CannonBall()"

}

void CannonBall::Init(std::string TextureName, sf::Vector2i &playerPosition, sf::Vector2i &piratePosition)
{
//Local Variables

//Main "Init()"
	BulletPosition.x = playerPosition.x;
	BulletPosition.y = playerPosition.y;

	BulletPositionTarget.x = piratePosition.x;
	BulletPositionTarget.y = piratePosition.y;
	
	sf::Vector2i BulletPositionHidden(999,999);
	



	BulletTexture.loadFromFile(TextureName.c_str()); //We Load The Enemy Bullet Texture.

	BulletSprite.setTexture(BulletTexture); //We Create The Sprite For The Emeny Bullet & We Attach The Texture.
	BulletSprite.setPosition(BulletPosition);
	BulletSprite.setOrigin(BulletTexture.getSize().x / 2,BulletTexture.getSize().y / 2);
}



sf::Sprite CannonBall::GetSprite()
{
//Local Variables

//Main "GetSprite()"

return BulletSprite;
}