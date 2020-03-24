#include "SFML\Graphics.hpp"

class Player
{
public:
		Player();
		~Player();
	int fishNo;
	int fishNoMax;
	int gems;

	void Currency (int gems,sf::Text &Arial);
	void Draw (sf::RenderWindow& window);


};

