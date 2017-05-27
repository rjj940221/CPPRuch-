//
// Created by Robert JONES on 2017/05/26.
//

#include <clocale>
#include "../include/Player.hpp"
#include "../include/Bullet.hpp"

Player::Player() : AEntity('^', 3), score(0) {}


int Player::getScore() const {
	return score;
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
