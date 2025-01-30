#ifndef KNIGHT__H__
#define KNIGHT__H__

#include "./Pos.h"

#ifndef N 
	#define N 8 
#endif

class Knight {
	public: 
		Pos pos;

		Pos move(const int &dir) const;
		bool setPos(const int &x, const int &y);
		Knight() = default;
};

	
Pos Knight::move(const int &dir) const { 
	static const short int map_x[N] = { -2, -2, -1, 1, 2, 2, 1, -1 }; 
	static const short int map_y[N] = { -1, 1, 2, 2, 1, -1, -2, -2 }; 
	
	Pos p; 

	p.set(pos.x + map_x[dir], pos.y + map_y[dir]);

	if (!p.validate())
		p.set(-1, -1);

	return p; 
}

/* . . 0 . 1 . . 
 * . 7 . . . 2 . 
 * . . . k . . . 
 * . 6 . . . 3 . 
 * . . 5 . 4 . .
 *
 * 0 = (k.y - 1, k.x - 2)
 * 1 = (k.y + 1, k.x - 2)
 * 2 = (k.y + 2, k.x - 1)
 * 3 = (k.y + 2, k.x + 1)
 * 4 = (k.y + 1, k.x + 2)
 * 5 = (k.y - 1, k.x + 2)
 * 6 = (k.y - 2, k.x + 1)
 * 7 = (k.y - 2, k.x - 1)
 *
 * x: [ 0 0 1 1 0 0 1 1 ] (+1)
 * y: ![x] (+1)
 *
 */ 

#endif
