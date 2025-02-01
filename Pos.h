#ifndef POS__H__
#define POS__H__

#include "constants.h"

class Pos {
	public: 
		int x;
		int y; 

		inline Pos(int _x = 0, int _y = 0) noexcept : x(_x), y(_y) {}; 
		
		inline void set(int _x, int _y) noexcept {
			this->x = _x;
			this->y = _y;
		}
		
		inline bool validate() const {
			return !(x < 0 || x >= N || y < 0 || y >= N);  
		} 
};

#endif
