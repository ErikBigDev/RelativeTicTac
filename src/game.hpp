#ifndef GAME_HPP
#define GAME_HPP


#include <vector>
using namespace std;

enum type{
	tic,
	tac
};


class shape{
public:
	int x ,y;
	type t;
	shape(int ix , int iy, type it): x(ix), y(iy) , t(it){};
};


shape** getVisableShapes(int & len);
#define dist 90

#endif
