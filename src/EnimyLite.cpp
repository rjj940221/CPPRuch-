//
// Created by Robert JONES on 2017/05/27.
//

#include <clocale>
#include "../include/EnimyLite.hpp"
#include "../include/Bullet.hpp"

EnimyLite::EnimyLite(int locx, int locy) : AEntity('*', 1) {
	this->yLoc = locy;
	this->xLoc = locx;
	this->yVolocity = 1;
	this->xVolocity = 0;
}

AEntity *EnimyLite::shoot() {
	return new Bullet(0, -1, this->xLoc, this->yLoc);
}
