#ifndef KNIGHT__H__
#define KNIGHT__H__

#include "Pos.h"
#include "constants.h"

class Knight {	
	private: 
		static constexpr int map_x[KNIGHT_M] = { -2, -2, -1, 1, 2, 2, 1, -1 }; 
		static constexpr int map_y[KNIGHT_M] = { -1, 1, 2, 2, 1, -1, -2, -2 }; 

	public: 
		Pos pos;

		inline Pos move(int dir) const { 
			return Pos(pos.x + map_x[dir], pos.y + map_y[dir]);
		}

		Knight() = default;
};


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
