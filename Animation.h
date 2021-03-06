#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
	public:
		Animation();
		Animation(int x, int y, int width, int height, int nFrames, float holdTime, sf::Texture texture);
		~Animation();

		void advance();
		void applyToSprite(sf::Sprite& s);
		void update(float dt);

	private:
		float holdTime;
		sf::Texture texture;
		std::vector<sf::IntRect> frames;
		int currentFrame = 0;
		float time = 0;
};

