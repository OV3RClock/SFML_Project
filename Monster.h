#pragma once

#include "Entity.h"
#include "Lifebar.h"
#include "Player.h"
#include "Animation.h"

class Monster : public Entity
{
	public:
		Monster(int dim, float hp, sf::Texture& texture, sf::Vector2f pos);
		~Monster();

		float getSpeed();
		sf::Vector2f getVelocity();
		sf::Vector2f getPosition();
		sf::Sprite getSprite();
		sf::Vector2f Monster::getTarget();
		
		void setSpeed(float f);
		void setHP(int i);

		bool isPlayerInRange(sf::Vector2f& player);
		bool isOnTarget(int i);
		bool isHit(Player player);
		bool monsterHitPlayer(Player player);
		void setDirection();

		void moveToTarget(sf::Vector2f& player);
		void takeDmg(int dmg);

		void normalize(sf::Vector2f& velocity);
		void update(float dt, Player& player, bool& isTouched);
		void drawMonster(sf::RenderWindow& rw);
		
	protected:
		float monsterSpeed = 0;
		int numberTarget = 0;
		float elapsedTime = 0;
		LifeBar monsterLifeBar;
		sf::Vector2f velocity;
		sf::Vector2f target;
		std::vector<sf::Vector2f> path;

		enum class AnimationIndex
		{
			Up,
			Left,
			Down,
			Right,
			Count
		};
		Animation animations[int(AnimationIndex::Count)];
		AnimationIndex curAnimation = AnimationIndex::Down;
};