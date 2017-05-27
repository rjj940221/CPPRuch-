//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/WallLight.hpp"

WallLight::WallLight(void) : AEntity('#', 1000, 1) {
}

WallLight::WallLight(WallLight const &wl) : AEntity('#', 1000, 1) {
	*this = wl;
}

WallLight WallLight::operator=(WallLight const &rhs) {
	(void) rhs;
	return (*this);
}

WallLight::~WallLight(void) {
}

WallLight::WallLight(int x, int y, float volx, float voly) : AEntity('#', 1000, 1) {
	this->xLoc = x;
	this->yLoc = y;
	this->xVolocity = volx;
	this->yVolocity = voly;

}
