//
// Created by Robert JONES on 2017/05/27.
//

#include <clocale>
#include "../include/EnimyLite.hpp"
#include "../include/Bullet.hpp"

EnimyLite::EnimyLite(int locx, int locy) : AEntity('*', 1), AShip(50) {
	this->yLoc = locy;
	this->xLoc = locx;
	this->yVolocity = 0.2;
	this->xVolocity = 0;

}

AEntity *EnimyLite::shoot() {
	return new Bullet(0, 1, this->xLoc, this->yLoc);
}

EnimyLite::EnimyLite(EnimyLite const & el) : AEntity('*', 1), AShip(20) {
	*this = el;
}

EnimyLite EnimyLite::operator=(EnimyLite const & rhs)
{
	this->yLoc = rhs.getYLoc();
	this->xLoc = rhs.getXLoc();
	this->yVolocity = rhs.getYVolocity();
	this->xVolocity = rhs.getXVolocity();
	return (*this);
}

EnimyLite::~EnimyLite(void)
{
}
