#ifndef ANIMATED_ENTITY_CLASS
#define ANIMATED_ENTITY_CLASS

#include <SFML/Graphics.hpp>

// The most basic functionality for all entities
// Movement, setting positions
// Hitbox ?

#include "Animation.h"

class AnimatedEntity : public Entity {
private:

	sf::Texture* animationTexture;

public:
	Animation* animation;

	sf::RectangleShape rect;

public:

	AnimatedEntity(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids, sf::Vector2f size = sf::Vector2f(1, 1), sf::Vector2f pos = sf::Vector2f(0, 0));

	AnimatedEntity(sf::Vector2f size = sf::Vector2f(1, 1), sf::Vector2f pos = sf::Vector2f(0, 0));

	virtual ~AnimatedEntity();

	// 1. Update the animation
	// 2. Move it according to velocity (no bounds checking)
	virtual void update(float deltaTime);

	// Drawrect to window
	virtual void render(sf::RenderWindow* w, float deltaTime);

	// Use pos += velocity * deltaTime
	virtual void move(float deltaTime);

	void setTexture(sf::Texture* t);

};

#endif // !ANIMATED_ENTITY_CLASS
