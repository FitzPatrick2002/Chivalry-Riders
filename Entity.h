#ifndef ENTITY_CLASS
#define ENTITY_CLASS

#include <SFML/Graphics.hpp>

// The most basic functionality for all entities
// Movement, setting positions
// Hitbox ?


class Entity {
private:

protected:

	sf::Vector2f velocity;

public:

	Entity();

	virtual ~Entity();

	virtual void update(float deltaTime) = 0;

	virtual void render(sf::RenderWindow* w, float deltaTime) = 0;

	virtual void move(float deltaTime) = 0;
};

#endif // !ENTITY_CLASS
