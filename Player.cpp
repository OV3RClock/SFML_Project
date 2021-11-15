#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"
#include "Player.h"
#include "Animation.h"
#include "Weapon.h"

using namespace sf;
using namespace std;

Player::Player(int dim, Texture& texture, Vector2f& pos, Weapon w) : Entity(200, pos), baguette(w)
{
	animations[(int)AnimationIndex::Up] = Animation(3 * dim, 3 * dim, dim, dim, 3, 0.1, texture);
	animations[(int)AnimationIndex::Left] = Animation(3 * dim, 1 * dim, dim, dim, 3, 0.1, texture);
	animations[(int)AnimationIndex::Down] = Animation(3 * dim, 0 * dim, dim, dim, 3, 0.1, texture);
	animations[(int)AnimationIndex::Right] = Animation(3 * dim, 2 * dim, dim, dim, 3, 0.1, texture);
	animations[(int)AnimationIndex::idleUp] = Animation(4 * dim, 3 * dim, dim, dim, 1, 10, texture);
	animations[(int)AnimationIndex::idleLeft] = Animation(4 * dim, 1 * dim, dim, dim, 1, 10, texture);
	animations[(int)AnimationIndex::idleDown] = Animation(4 * dim, 0 * dim, dim, dim, 1, 10, texture);
	animations[(int)AnimationIndex::idleRight] = Animation(4 * dim, 2 * dim, dim, dim, 1, 10, texture);
	sprite.setPosition(pos);
}
Player::~Player()
{
}

float Player::getSpeed()
{
    return playerSpeed;
}
Vector2f Player::getPosition()
{
	return position;
}
Vector2f Player::getVelocity()
{
    return velocity;
}

Weapon Player::getWeapon()
{
	return baguette;
}

void Player::setSpeed(float f)
{
	playerSpeed = f;
}
void Player::setDirection(sf::Vector2f& dir)
{
	if (dir.x > 0.0f)
	{
		curAnimation = AnimationIndex::Right;
	}
	else if (dir.x < 0.0f)
	{
		curAnimation = AnimationIndex::Left;
	}
	else if (dir.y < 0.0f)
	{
		curAnimation = AnimationIndex::Up;
	}
	else if (dir.y > 0.0f)
	{
		curAnimation = AnimationIndex::Down;
	}
	else
	{
		if (velocity.x > 0.0f)
		{
			curAnimation = AnimationIndex::idleRight;
		}
		else if (velocity.x < 0.0f)
		{
			curAnimation = AnimationIndex::idleLeft;
		}
		else if (velocity.y < 0.0f)
		{
			curAnimation = AnimationIndex::idleUp;
		}
		else if (velocity.y > 0.0f)
		{
			curAnimation = AnimationIndex::idleDown;
		}
	}
    velocity = dir * playerSpeed;
}
void Player::setVelocityX(float f)
{
	velocity.x = f;
}
void Player::setVelocityY(float f)
{
	velocity.y = f;
}
void Player::setHP(int i)
{
    entityHP = i;
    playerLifeBar.setValue(entityHP);
}

void Player::takeDmg(int i)
{
    entityHP -= i;
    playerLifeBar.setValue(entityHP);
}

void Player::normalize(Vector2f& vect)
{
    float norme = sqrt((vect.x * vect.x) + (vect.y * vect.y));
    if (norme != 0)
    {
        vect.x = ((vect.x) / norme) * playerSpeed;
        vect.y = ((vect.y) / norme) * playerSpeed;
    }
}
void Player::update(float dt, bool isSprinting, bool& isAttacking)
{
    normalize(velocity);
    sprite.move(velocity * dt);
	position = sprite.getPosition();
	baguette.update(dt, isAttacking);

    if (isSprinting) 
    {
        animations[int(curAnimation)].update(dt*2);
        animations[int(curAnimation)].applyToSprite(sprite);
    }
    else
    {
        animations[int(curAnimation)].update(dt);
        animations[int(curAnimation)].applyToSprite(sprite);
    }
    playerLifeBar.setPosition(position.x, position.y - 6);
	baguette.setPosition(position.x + 8, position.y + 8);

	switch (curAnimation)
	{
		case Player::AnimationIndex::Up:
			baguette.setStartAngle(180);
			break;
		case Player::AnimationIndex::Left:
			baguette.setStartAngle(90);
			break;
		case Player::AnimationIndex::Down:
			baguette.setStartAngle(0);
			break;
		case Player::AnimationIndex::Right:
			baguette.setStartAngle(270);
			break;
	}
}
void Player::drawPlayer(sf::RenderWindow& rw, bool isAttacking)
{
	if (isAttacking)
	{
		rw.draw(baguette);
	}
	rw.draw(sprite);
    rw.draw(playerLifeBar);
}

