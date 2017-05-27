//
// Created by Robert JONES on 2017/05/27.
//

#ifndef ENIMYWIDE_HPP
#define ENIMYWIDE_HPP


class EnimyWide : public AShip {
private:
	EnimyWide(void);


public:
	EnimyWide(int locx, int locy);
	AEntity *shoot();

	EnimyWide(EnimyWide const & el);
	EnimyWide operator=(EnimyWide const & rhs);
	~EnimyWide(void);
};


#endif //RUSH00_ROJONES_ENIMYWIDE_HPP
