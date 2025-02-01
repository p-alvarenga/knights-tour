#include <stdio.h>
#include <time.h>
#include <cmath>

#include "constants.h"
#include "Pos.h"
#include "Knight.h"
#include "printMatrix.h"

void printMatrix(int matrix[N][N]);
bool solveTour(Knight k, int it, int matrix[N][N]);
bool availableMove(Pos p, int matrix[N][N]);

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

bool solveTour(Knight k, int it, int matrix[N][N]) {
	static Pos p; // helper

	Knight knext;

	if (it == N_MAX + 1) {
		return 1;
	}

	for (int i = 0; i < KNIGHT_M; i++) {
		p = k.move(i);

		if (p.validate() && matrix[p.x][p.y] == 0) {
			matrix[p.x][p.y] = it;
			knext.pos = p;

			if (solveTour(knext, it + 1, matrix)) {
				return 1;
			} else {
				matrix[knext.pos.x][knext.pos.y] = 0;
				i += OPT_MV;
			}
		}
	}

  return 0;
}
// also, using a .h is better, isn'it? 
// not only for printMatrix(), but, maybe, for solveTour(...)? 
// _MAYBE_ turning solveTour into a clas 

