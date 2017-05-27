//
// Created by Robert JONES on 2017/05/27.
//

#ifndef RUSH00_ROJONES_ENIMYLITE_HPP
#define RUSH00_ROJONES_ENIMYLITE_HPP


#include "AEntity.hpp"
#include "Ship.hpp"

class EnimyLite : public Ship {
public:
	EnimyLite(int locx, int locy);
	AEntity *shoot();
};


#endif //RUSH00_ROJONES_ENIMYLITE_HPP
