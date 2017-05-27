//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/EnimyWide.hpp"
#include "../include/Ship.hpp"
#include "../include/Bullet.hpp"

EnimyWide::EnimyWide(int locx, int locy) : AEntity('*', 1), AShip(0) {
	this->yLoc = locy;
	this->xLoc = locx;
	this->yVolocity = 0.2;
	this->xVolocity = 0;

}

AEntity *EnimyWide::shoot() {
	return new Bullet(0, 1, this->xLoc, this->yLoc);
}

EnimyWide::EnimyWide(EnimyWide const & el) : AEntity('*', 1), AShip(20) {
	*this = el;
}

EnimyWide EnimyWide::operator=(EnimyWide const & rhs)
{
	this->yLoc = rhs.getYLoc();
	this->xLoc = rhs.getXLoc();
	this->yVolocity = rhs.getYVolocity();
	this->xVolocity = rhs.getXVolocity();
	return (*this);
}

EnimyWide::~EnimyWide(void)
{
}