//
// Created by Robert JONES on 2017/05/26.
//

#ifndef ROJONES_IENTITY_HPP
#define ROJONES_IENTITY_HPP

#include <string>

class AEntity {
protected:
	int width;
	int lives;
	int damage;
	float xLoc;
	float yLoc;
	float xVolocity;
	float yVolocity;
	char symbol;
public:
	AEntity();

	int getWidth() const;

	/*For Canonical Purposes.*/
	AEntity(AEntity const &ae);

	AEntity operator=(AEntity const &rhs);

	AEntity(char symbol);

	AEntity(char symbol, int width);

	AEntity(char symbol, int lives, int width);
	//AEntity(int xVolocity, int yVolocity);
	int getXLoc() const;

	int getYLoc() const;

	bool update(int mx, int my);

	unsigned int getSymbol() const;

	virtual ~AEntity();

	float getXVolocity() const;

	int getLives() const;

	int getDamage() const;

	int takeDamage();

	void setXVolocity(int xVolocity);

	float getYVolocity() const;

	void setYVolocity(int yVolocity) {
		AEntity::yVolocity = yVolocity;
	}

	void setLocation(int x, int y);
};

#endif //ROJONES_IENTITY_HPP
