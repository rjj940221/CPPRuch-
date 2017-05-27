//
// Created by Robert JONES on 2017/05/27.
//

#ifndef RUSH00_ROJONES_WALLLIGHT_HPP
#define RUSH00_ROJONES_WALLLIGHT_HPP


#include "AEntity.hpp"

class WallLight : public AEntity {
	public:
		WallLight(void);
		WallLight(int x, int y, float volx, float voly);
		WallLight(WallLight const & wl);
		WallLight operator=(WallLight const & wl);
		~WallLight(void);
};


#endif //RUSH00_ROJONES_WALLLIGHT_HPP
