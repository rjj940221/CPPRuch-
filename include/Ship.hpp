//
// Created by Robert JONES on 2017/05/27.
//

#ifndef RUSH00_ROJONES_SHIP_HPP
#define RUSH00_ROJONES_SHIP_HPP


#include "AEntity.hpp"

class AShip : public virtual AEntity{
public:
	virtual AEntity *shoot() = 0;
};


#endif //RUSH00_ROJONES_SHIP_HPP
