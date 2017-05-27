//
// Created by Robert JONES on 2017/05/27.
//

#ifndef BULLET_HPP
#define BULLET_HPP


#include "AEntity.hpp"

class Bullet : public AEntity {
private:
	Bullet(void);
public:
	Bullet(float volX, float volY, float locX, float locY);
	Bullet(Bullet const & b);
	Bullet operator=(Bullet const & rhs);
	~Bullet(void);
};


#endif //BULLET_HPP
