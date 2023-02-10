#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

int main()
{

	//The game will always be in one of four states
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING};

	//Start with the GAME_OVER state
	State state = State::GAME_OVER;

	//Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena", Style::Fullscreen);

	//Create an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Clock for timing everything
	Clock clock;

	//How long has the PLAYING state been active
	Time gameTimeTotal;

	//Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;

	//Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;

	//Create an instance of the player class
	Player player;

	//The boundaries of the arena
	IntRect arena;

	//The main game loop
	while (window.isOpen())
	{
		//*************
		//Handle Input
		//*************

		//Handle events by polling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				//Pause a game while playing
				if (event.key.code == Keyboard::Return && state = State::PLAYING)
				{
					state = State::PAUSED;
				}

				//Continue from pause
				else if (event.key.code == Keyboard::Return && state == State::PAUSED)
				{
					state = State::PLAYING;
					//Reset the clock to avoid a frame jump
					clock.restart();
				}

				//Start a new game if in GAME_OVER
				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}
				if (state == State::PLAYING)
				{

				}
			}
		} //End even polling

		//Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//Handle WASD while playing
		if (state == State::PLAYING)
		{
			//W for Up
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}

			//S for Down
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}

			//A for Left
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}

			//D for Right
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}

		} //End WASD for movement

	} //End of game loop


	return 0;
}