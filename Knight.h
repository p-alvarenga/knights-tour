#ifndef KNIGHT__H__
#define KNIGHT__H__

#include "Point.h"
#include "constants.h"


class Knight {	
	private:                        
		static constexpr int map_x[KNIGHT_MV] = { -2, -2, +1, +1, -1, -1, +2, +2 };
		static constexpr int map_y[KNIGHT_MV] = { -1, +1, -2, +2, -2, +2, -1, +1 };

	public:
		Point pos; 

		inline Point move(int dir) {
			return Point(pos.x + map_x[dir], pos.y + map_y[dir]);
		} 
	
		inline Point movePoint(int dir, Point &p) {
			return Point(p.x + map_x[dir], p.y + map_y[dir]);
		}

	
		void setPriority(int priority[8]) {
			static int acc{-1};
			static int calc_moves = {0};

			static Point k_mv;

			for (int m = 0; m < 8; m++) {
				priority[m] = -1;
				acc = -1; // every move can return to it's initial state. 

				k_mv = move(m);
				
				if (!k_mv.validate())
					continue;

				for (int i = 0; i < 8; i++) {
					if (movePoint(i, k_mv).validate()) { 
						acc++;
					}
				}
				

				priority[m] = acc;
			}

			return;
		}


		inline Knight(int x_ = 0, int y_ = 0) {
			pos.set(x_, y_);
		};

};

/* . 0 . 1 .  
 * 4 . . . 5  
 * . . k . .  
 * 2 . . . 3  
 * . 6 . 7 . 
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
