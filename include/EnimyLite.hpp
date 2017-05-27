//
// Created by Robert JONES on 2017/05/27.
//

#ifndef ENIMYLITE_HPP
#define ENIMYLITE_HPP


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


#endif //ENIMYLITE_HPP
