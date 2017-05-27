//
// Created by Robert JONES on 2017/05/27.
//

#ifndef RUSH00_ROJONES_SHIP_HPP
#define RUSH00_ROJONES_SHIP_HPP


#include "AEntity.hpp"

class AShip : public virtual AEntity{
private:
	int ShootChance;
public:
	AShip(int ShootChance);

	virtual AEntity *shoot() = 0;

	int getShootChance() const;
};


#endif //RUSH00_ROJONES_SHIP_HPP
