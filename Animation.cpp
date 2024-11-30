#include "Animation.h"

Animation::Animation(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids)
{
	this->stripsWidths = strpWids;
	this->stripHeight = strpHs;

	this->totalTime = 0.0f;

	this->currentImage.x = 0;
	this->currentImage.y = 0;

	// Find max amount of strips in one row so that we can get the width of one strip
	int m = *std::max(strpWids.begin(), strpWids.end());

	uvRect.width = t->getSize().x / m;
	uvRect.height = t->getSize().y / strpHs;

}

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::initAnimation(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids)
{
	this->stripsWidths = strpWids;
	this->stripHeight = strpHs;

	this->totalTime = 0.0f;

	this->currentImage.x = 0;
	this->currentImage.y = 0;

	// Find max amount of strips in one row so that we can get the width of one strip
	int m = *std::max_element(strpWids.begin(), strpWids.end());

	uvRect.width = t->getSize().x / m;
	uvRect.height = t->getSize().y / strpHs;
}

void Animation::selectRow(u_int i)
{
	if (i >= 0 && i < this->stripHeight)
		this->currentImage.y = i;
	else
		std::cerr << "Cannot set the animation y, i < 0 or i > animation strip height\n";
}

void Animation::update(float deltaTime)
{
	totalTime += deltaTime;

	// Load next frame of animation and reset timer
	if (totalTime >= switchTime) {
		this->currentImage.x++;

		if (currentImage.x >= stripsWidths[currentImage.y])
			currentImage.x = 0;

		totalTime = 0.f;
	}

	this->uvRect.left = currentImage.x * uvRect.width;
	this->uvRect.top = currentImage.y * uvRect.height;
}
