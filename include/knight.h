#ifndef KNIGHT__H__
#define KNIGHT__H__

#include "constants.h"
#include "pos.h"

class Knight : public Pos { //# < !
	private: 
		static constexpr int map_x[KNIGHT_M] = { -2, -2, -1, 1, 2, 2, 1, -1 };
		static constexpr int map_y[KNIGHT_M] = { -1, 1, 2, 2, 1, -1, -2, -2 };
	
	public: 
		Knight(int _x = INIT_X, int _y = INIT_Y) 
		{
			this->x = _x; 
			this->y = _y;
		} 

		inline Knight move(int dir) const;
};

inline Knight Knight::move(int dir) const 
{
	return Knight(x + map_x[dir], y + map_y[dir]); 
}


/* . 0 . 1 .  
 * 7 . . . 2  
 * . . k . .  
 * 6 . . . 3  
 * . 5 . 4 . 
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
 */ 

#endif
