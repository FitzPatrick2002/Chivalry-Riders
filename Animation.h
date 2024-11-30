#ifndef ANIMATION_CLASS
#define ANIMATION_CLASS

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>


using u_int = unsigned int;

class Animation {
	//sf::Vector2u imageCount; // Amount of images in strip horizontal and vertical
private:
	u_int stripHeight;
	std::vector<u_int> stripsWidths;

	float totalTime;
	float switchTime;

	sf::Vector2u currentImage; // Selected row and current x'th image in the strip

public:

	sf::IntRect uvRect;

public:

	Animation(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids);

	Animation();

	~Animation();

	// Use it if default constructor has been used
	void initAnimation(sf::Texture* t, u_int strpHs, std::vector<u_int> strpWids);

	// To do: Make it select the row based on an enum like: walk -> 0, N,E,S,W, die -> 4, etc.
	void selectRow(u_int i);

	// Updates the current frame: currentImage.x 
	void update(float deltaTime);

};

#endif //!ANIMATION_CLASS