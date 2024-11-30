#ifndef GAME_CLASS
#define GAME_CLASS

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "AnimatedEntity.h"

using v2f = sf::Vector2f;
using u_int = unsigned int;

class Game {
private:

	sf::RenderWindow* window;
	sf::Event ev;

	float windowHeight = 768; // Floats so that we don;t have to recast them later
	float windowWidth = 1024;

	//Temp
	std::vector<sf::RectangleShape> shapes;
	// --- 

	// Temp
	sf::Texture cavTexture;
	// ---

	AnimatedEntity cavalier;

	sf::View mainView; // Main view focused on the player (smaller than the entire map), can be scrolled in and out, follows the playuer as it moves
	sf::View miniMapView; // Minimap in the top right corner of the screen. 

	float mainZoom = 1.0f;

public:

	Game();
	
	~Game();

	// Inits the game variables
	void initVariables();

	// ------------- Handling user Input ----------------- //

	void handleUserKeybordInput();

	void handleScrollInput();

	// While that pulls events from the vents stack and calls approprite function. ex. sf::Event::KeyPressed -> this->handleUserKeybordInput()
	void pollEvents();

	// Updates states of things, like settingposition, moving them, updating animation, etc..
	void update(float deltaTime);

	// Renders stuff with window->draw(...)
	void render(float deltaTime);

	// ------------------- Views, Camera, minimap ----------------- //
	
	// Called in pollEvents for sf::Event::resize -> resizes all views so that the aspect ratio is preserved when we resize the window (like make it fullscreen)
	void resizeView();

	bool getWindowIsOpen();

	void zoomCameraAndMiniMap(float delta);

	// ----------------- Enemies ! ------------------------------ //

	void initEnemies();

};


#endif // !GAME_CLASS
