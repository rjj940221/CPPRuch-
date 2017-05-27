//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/Ship.hpp"

int AShip::getShootChance() const {
	return ShootChance;
}

AShip::AShip(int ShootChance) : ShootChance(ShootChance) {}
