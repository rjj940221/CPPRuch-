//
// Created by Robert JONES on 2017/05/26.
//

#include <clocale>
#include "../include/Player.hpp"
#include "../include/Bullet.hpp"

Player::Player() : AEntity('^', 3, 1), AShip(0), score(0) {}

Player::Player(Player const &plr) : AEntity('^', 3, 1), AShip(0), score(0) {
	*this = plr;
}

Player Player::operator=(Player const &rhs) {
	this->score = rhs.getScore();
	return (*this);
}

Player::~Player(void) {
}

int Player::getScore() const {
	return score;
}

void Player::addToScore(int amount)
{
	score += amount;
}

void Player::moveLeft() {
	xLoc--;
	xLoc = (xLoc < 0) ? 0 : xLoc;
}

void Player::moveRight(int bound) {
	xLoc++;
	xLoc = (xLoc > bound) ? bound : xLoc;
}

void Player::moveUp() {
	yLoc--;
	yLoc = (yLoc < 0) ? 0 : yLoc;
}

void Player::moveDown(int bound) {
	yLoc++;
	yLoc = (yLoc > bound) ? bound : yLoc;
}

AEntity *Player::shoot() {
	return new Bullet(0, -1, this->xLoc, this->yLoc);
}
