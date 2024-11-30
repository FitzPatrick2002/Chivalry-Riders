#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::initVariables()
{
	this->window = new sf::RenderWindow(sf::VideoMode(u_int(windowWidth), u_int(windowHeight)), "Chivalry Riders");

	this->mainView.setCenter(windowWidth / 2.f, windowHeight / 2.f);
	this->mainView.setSize(300.0f, 300.0f);

	this->miniMapView.setCenter(windowWidth / 2.0f, windowHeight / 2.0f);
	this->miniMapView.setSize(windowWidth, windowHeight);

	this->mainView.setViewport(sf::FloatRect(0.f, 0.f, 1.0f, 1.0f)); // Top left corner, then the width and height
	this->miniMapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));

	// --- temp feature
	shapes.resize(5);

	float i = 0;
	for (auto& e : shapes) {
		e.setSize(v2f(100.0f, 100.0f));
		e.setOrigin(v2f(50.0f, 50.0f));
		e.setPosition(v2f(i*1024/shapes.size(), i* 768/shapes.size()));
		i++;
	}
	// --- temp feature end
}

void Game::handleUserKeybordInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

	}

}

void Game::handleScrollInput()
{
	float delta = ev.mouseWheelScroll.delta;

	this->zoomCameraAndMiniMap(delta);

}

void Game::pollEvents()
{
	while (window->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			this->handleUserKeybordInput(); //Handle the user input
			
			break;
		case sf::Event::MouseWheelScrolled:
			this->handleScrollInput();

			break;
		case sf::Event::Resized: // We want to resize view to correct width so that aspect ratio is preserved
			this->resizeView();
			break;

		}
	}

}

void Game::update(float deltaTime)
{
	std::cout << "Delta time: " << deltaTime << "\n";

	this->cavalier.update(deltaTime);
}

void Game::render(float deltaTime)
{
	this->window->clear();


	this->window->setView(this->mainView);

	// --- temp feature
	for (auto& e : shapes)
		this->window->draw(e);
	//-- temp feature end

	this->cavalier.render(this->window, deltaTime);

	this->window->setView(miniMapView);

	// --- temp feature
	for (auto& e : shapes)
		this->window->draw(e);
	//-- temp feature end

	this->cavalier.render(this->window, deltaTime);

	this->window->display();
}

void Game::resizeView()
{
	float aspectRatio = float(window->getSize().x) / float(window->getSize().y);

	this->mainView.setSize(300.0f * aspectRatio * mainZoom, 300.0f * aspectRatio * mainZoom);
	this->miniMapView.setSize(windowWidth * aspectRatio * mainZoom, windowWidth * aspectRatio * mainZoom);
}

bool Game::getWindowIsOpen()
{
	return this->window->isOpen();
}

void Game::zoomCameraAndMiniMap(float delta)
{
	this->mainZoom -= delta * 0.1;

	this->mainView.setSize(300.0f * mainZoom, 300.0f * mainZoom);
	this->miniMapView.setSize(windowWidth * mainZoom, windowWidth * mainZoom);
}

void Game::initEnemies()
{
	//Temp
	this->cavTexture.loadFromFile("Graphics/Cavalier.png");

	std::vector<u_int> stripsLengths = { 8, 6, 6, 3, 7, 2, 7 };
	int stripsRowsNum = 7;

	// ---
	
	this->cavalier.rect.setSize(sf::Vector2f(100.0f, 100.0f));
	this->cavalier.rect.setOrigin(50.0f, 50.0f);
	this->cavalier.rect.setPosition(100.0f, 100.0f);
	this->cavalier.setTexture(&cavTexture);

	this->cavalier.animation->initAnimation(&this->cavTexture, stripsRowsNum, stripsLengths);
}
