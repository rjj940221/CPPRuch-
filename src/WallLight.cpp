//
// Created by Robert JONES on 2017/05/27.
//

#include "../include/WallLight.hpp"

WallLight::WallLight(void) : AEntity('_')
{
}

WallLight::WallLight(WallLight const & wl) : AEntity('_')
{
	*this = wl;
}

WallLight WallLight::operator=(WallLight const & rhs)
{
	(void)rhs;
	return (*this);
}

WallLight::~WallLight(void)
{
}
