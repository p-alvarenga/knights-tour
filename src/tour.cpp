#include "../include/tour.h"

bool Tour::solve(Knight kn, int it)
{	
	if (it == N_MAX + 1) return true; 
	
	Knight kn_buf; 

	for (int dir = 0; dir < KNIGHT_M; dir++) 
	{
		kn_buf = kn.move(dir);

		if (kn_buf.validate() && matrix[kn_buf.x][kn_buf.y] == 0) 
		{
			matrix[kn_buf.x][kn_buf.y] = it; 

			if (!solve(kn_buf, it + 1))
			{
				matrix[kn_buf.x][kn_buf.y] = 0; 
				dir += OPT_MV;
			}
			else return true; 
		}
	}

	return false;
}
