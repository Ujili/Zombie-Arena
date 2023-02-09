#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player 
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	//Where is the player at
	Vector2f m_Position;

	//Player Sprite
	Sprite m_Sprite;

	//And texture
	//CHANGES HERE SOON
	Texture m_Texture;

	//What is the screen resolution
	Vector2f m_Resolution;

	//What size is the current arena
	IntRect m_Arena;
	
	//How big is each tile of the arena
	int m_Tilesize;

	//Which direction is the character currently moving
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	//How much health does the player have?
	int m_Health;
	//What is the max health the player can have?
	int m_MaxHealth;

	//When was the player last hit?
	Time m_LastHit;

	//Speed in pixels per second
	float m_Speed;

	//All Public functions will come soon

public:
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	//Call this after every game
	void resetPlayerStats();

	//Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	//How long ago was the player last hit
	Time getLastHitTime();

	//Where is the player
	FloatRect getPosition();

	//Where is the center of the player
	Vector2f getCenter();

	//What angle is the player facing
	float getRotation();

	//Send a copy of the sprite to the main function
	Sprite getSprite();

	//The next four functions move the player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//Stop the player moving in a specific direction
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDOwn();

	//This function is called every frame
	void update(float elapsedTime, Vector2i mousePosition);

	//Give the player a speed boost
	void upgradeSpeed();

	//Give the player some health
	void upgradeHealth();

	//Increases the max health a player can have
	void increaseHealthLevel(int amount);

	//How much health does the player have
	int getHealth();
	
};