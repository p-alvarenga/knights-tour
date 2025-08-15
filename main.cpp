#include <stdio.h>
#include <time.h>
#include <cmath>

#include "include/constants.h"
#include "include/pos.h"
#include "include/knight.h"
#include "include/print-matrix.h"

void printMatrix(int matrix[N][N]);
bool solveTour(Knight k, int it, int matrix[N][N]);

int main(void) {
	int matrix[N][N] = { 0 };

	Knight k;
	k.pos.set(INIT_X, INIT_Y);
	
	matrix[INIT_X][INIT_Y] = 1;

	printf("\nsolving for N = %i | OPT_MV = %i...\n\n", N, OPT_MV);

	clock_t begin = clock();
	solveTour(k, 2, matrix);
	clock_t end = clock();

	printMatrix(matrix);
	printf("> Time spent: %f\n", (double)(end - begin) / CLOCKS_PER_SEC); 

	return 0;
}

bool solveTour(Knight k, int it, int matrix[N][N]) 
{
	static Pos p; // helper

	Knight k_next;

	if (it == N_MAX + 1) return true;

	for (int i = 0; i < KNIGHT_M; i++) 
	{
		p = k.move(i);

		if (p.validate() && matrix[p.x][p.y] == 0) 
		{
			matrix[p.x][p.y] = it;
			k_next.pos = p;

			if (!solveTour(k_next, it + 1, matrix))
			{
				matrix[k_next.pos.x][k_next.pos.y] = 0;
				i += OPT_MV;
			}
			else return true;	
		}
	}


	return false;
}
// also, using a .h is better, isn'it? 
// not only for printMatrix(), but, maybe, for solveTour(...)? 
// _MAYBE_ turning solveTour into a class
