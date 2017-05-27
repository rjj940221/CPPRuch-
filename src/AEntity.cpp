//
// Created by Robert JONES on 2017/05/26.
//

#include <math.h>
#include "../include/AEntity.hpp"

AEntity::AEntity() : lives(1), damage(1), symbol('-') {}

AEntity::AEntity(char symbol) : lives(1), damage(1), symbol(symbol) {
}

AEntity::AEntity(AEntity const &ae) {
	*this = ae;
}

AEntity AEntity::operator=(AEntity const &rhs) {
	this->lives = rhs.getLives();
	this->damage = rhs.getDamage();
	this->xLoc = rhs.getXLoc();
	this->yLoc = rhs.getYLoc();
	this->xVolocity = rhs.getXVolocity();
	this->yVolocity = rhs.getYVolocity();
	this->symbol = rhs.getSymbol();

	return (*this);
}

int AEntity::getLives() const {
	return lives;
}

int AEntity::getDamage() const {
	return damage;
}

AEntity::AEntity(char symbol, int lives) : lives(lives), damage(1), symbol(symbol) {

}

int AEntity::takeDamage() {
	lives--;
	return lives;
}

int AEntity::getXLoc() const {
	return (int) (xLoc);
}

int AEntity::getYLoc() const {
	return (int) (yLoc);
}

bool AEntity::update(int mx, int my) {
	xLoc += xVolocity;
	yLoc += yVolocity;

	return (xLoc > -1 && xLoc < mx && yLoc > -1 && yLoc < my);
}

void AEntity::setXVolocity(int xVolocity) {
	AEntity::xVolocity = xVolocity;
}

void AEntity::setLocation(int x, int y) {
	xLoc = x;
	yLoc = y;
}

float AEntity::getYVolocity() const {
	return yVolocity;
}

float AEntity::getXVolocity() const {
	return xVolocity;
}

AEntity::~AEntity() {

}

unsigned int AEntity::getSymbol() const {
	return (const unsigned int) symbol;
}
