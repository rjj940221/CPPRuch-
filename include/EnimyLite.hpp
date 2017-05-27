//
// Created by Robert JONES on 2017/05/27.
//

#ifndef RUSH00_ROJONES_ENIMYLITE_HPP
#define RUSH00_ROJONES_ENIMYLITE_HPP


#include "AEntity.hpp"
#include "Ship.hpp"

class EnimyLite : public AShip {
private:
	EnimyLite(void);


public:
	EnimyLite(int locx, int locy);
	AEntity *shoot();

	EnimyLite(EnimyLite const & el);
	EnimyLite operator=(EnimyLite const & rhs);
	~EnimyLite(void);
};


#endif //RUSH00_ROJONES_ENIMYLITE_HPP
