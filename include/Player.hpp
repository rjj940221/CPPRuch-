//
// Created by Robert JONES on 2017/05/26.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "AEntity.hpp"
#include "Ship.hpp"

class Player : public AShip {
private:

	int score;
public:
	Player();

	Player(Player const & plr);

	Player operator=(Player const & rhs);

	int getScore() const;

	void moveLeft();

	void moveRight(int bound);

	void moveUp();

	void moveDown(int bound);

	AEntity *shoot();

	~Player(void);
};


#endif //PLAYER_HPP
