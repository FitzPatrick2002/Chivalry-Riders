#include "Entity.h"
#include "AnimatedEntity.h"

AnimatedEntity::AnimatedEntity(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids, sf::Vector2f size, sf::Vector2f pos) : Entity()
{
	this->animation = new Animation(t, strpHs, strpWids);
	this->animationTexture = t;

	this->rect.setTexture(t);
	this->rect.setSize(size);
	this->rect.setOrigin(size.x / 2.0f, size.y / 2.0f);
	this->rect.setPosition(pos);

	this->velocity = sf::Vector2f(0.0f, 0.0f);

}

AnimatedEntity::AnimatedEntity(sf::Vector2f size, sf::Vector2f pos)
{
	this->animation = new Animation();

	this->rect.setSize(size);
	this->rect.setOrigin(size.x / 2.0f, size.y / 2.0f);
	this->rect.setPosition(pos);

	this->velocity = sf::Vector2f(0.0f, 0.0f);
}

AnimatedEntity::~AnimatedEntity()
{
	delete animation;
}

void AnimatedEntity::update(float deltaTime)
{
	this->animation->selectRow(0);
	this->animation->update(deltaTime);
	this->rect.setTextureRect(this->animation->uvRect);

	this->move(deltaTime);
}

void AnimatedEntity::render(sf::RenderWindow* w, float deltaTime)
{
	w->draw(this->rect);
}

void AnimatedEntity::move(float deltaTime)
{
	sf::Vector2f pos = this->rect.getPosition();

	pos.x += this->velocity.x * deltaTime;
	pos.y += this->velocity.y * deltaTime;

	this->rect.setPosition(pos);

	std::cout << "pos: " << this->rect.getPosition().x << " " << this->rect.getPosition().y << "\n";
}

void AnimatedEntity::setTexture(sf::Texture *t)
{
	this->animationTexture = t;
	this->rect.setTexture(t);
}
