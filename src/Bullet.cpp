//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/Bullet.hpp"

Bullet::Bullet(float volX, float volY, float locX, float locY) : AEntity('|') {
	this->yVolocity = volY;
	this->xVolocity = volX;
	this->xLoc = locX + volX;
	this->yLoc = locY + volY;
}

Bullet::Bullet(Bullet const & b) : AEntity('|')
{
	*this = b;
}

Bullet Bullet::operator=(Bullet const & rhs)
{
	this->symbol = (char) rhs.getSymbol();
	this->yVolocity = rhs.getYVolocity();
	this->xVolocity = rhs.getXVolocity();
	this->xLoc = rhs.getXLoc();
	this->yLoc = rhs.getYLoc();
	return (*this);
}

Bullet::~Bullet(void)
{
}
