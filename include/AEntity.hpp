//
// Created by Robert JONES on 2017/05/26.
//

#ifndef ROJONES_IENTITY_HPP
#define ROJONES_IENTITY_HPP

class AEntity {
protected:
	int lives;
	int damage;
	int xLoc;
	int yLoc;
	int xVolocity;
	int yVolocity;
	char symbol;
public:
	AEntity();

	/*For Canonical Purposes.*/
	AEntity(AEntity const & ae);
	AEntity operator=(AEntity const &rhs);

	AEntity(char symbol);

	AEntity(char symbol, int lives);
	//AEntity(int xVolocity, int yVolocity);
	int getXLoc() const;

	int getYLoc() const;

	bool update(int mx, int my);

	unsigned int getSymbol() const;

	virtual ~AEntity();

	int getXVolocity() const;

	int getLives() const;

	int getDamage() const;

	int takeDamage();

	void setXVolocity(int xVolocity);

	int getYVolocity() const;

	void setYVolocity(int yVolocity) {
		AEntity::yVolocity = yVolocity;
	}

	void setLocation(int x, int y);
};

#endif //ROJONES_IENTITY_HPP
