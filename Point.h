#ifndef POINT__H__
#define POINT__H__

#include "constants.h"

class Point {
	public: 
		int x, y; 

		inline Point(int _x = 0, int _y = 0): x(_x), y(_y) {}; 
		
		inline void set(int _x, int _y) noexcept {
			this->x = _x;
			this->y = _y;
		}
		
		inline bool validate() const {
			return !(x < 0 || x >= N || y < 0 || y >= N);  
		}

		inline bool operator==(Point &p_) const {
			return (x == p_.x && y == p_.y);
		}

		inline bool operator!=(Point &p_) const {
			return !(x == p_.x && y == p_.y);
		}
};


#endif
