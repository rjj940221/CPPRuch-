//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/Bullet.hpp"

Bullet::Bullet(int volX, int volY, int locX, int locY) : AEntity('|') {
	this->yVolocity = volY;
	this->xVolocity = volX;
	this->xLoc = locX + volX;
	this->yLoc = locY + volY;
}
