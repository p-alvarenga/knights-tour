#ifndef TOUR__H__
#define TOUR__H__

#include "constants.h"
#include "knight.h"

class Tour
{
	public:
		int matrix[N][N] = { 0 };
		
		Tour() 
		{ 
			matrix[INIT_X][INIT_Y] = 1;
		}
		
	bool solve(Knight kn, int it = 2);
};

#endif
