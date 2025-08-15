#ifndef POS__H__
#define POS__H__

#include "constants.h"

class Pos 
{
	public: 
		int x;
		int y; 

		Pos(int _x = 0, int _y = 0): 
			x(_x), 
			y(_y) 
		{;}
		
		inline void set(int _x, int _y);
		inline bool validate() const;
};

inline void Pos::set(int _x, int _y)
{
	this->x = _x; 
	this->y = _y;
}

inline bool Pos::validate() const 
{
	return !(x < 0 || x >= N || y < 0 || y >= N);
}

#endif
