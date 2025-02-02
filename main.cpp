#include <stdio.h>
#include <time.h>
#include <cmath>

#include "constants.h"
#include "Point.h"
#include "Knight.h"
#include "printMatrix.h"

bool solveTour(Knight k, int it, int matrix[N][N]);

int main(void) {
	int matrix[N][N] = {0};
	matrix[INIT_X][INIT_Y] = 1;

	Knight k(INIT_X, INIT_Y);
	Point p; 

	int priority[8] = {0};

	printf("\nsolving for N = %i | OPT_MV = %i...\n\n", N, OPT_MV);
	

	clock_t begin = clock();
	Priority(priority);

	clock_t end = clock()		

	double delta = (double)(end - begin)/CLOCKS_PER_SEC;

	for (int i = 0; i < 8; i++) {
		if (priority[i] < 0)
			continue;

		p = k.move(i);
		
		if(p.validate()) {
			matrix[p.x][p.y] = priority[i];
		}
	}
	printMatrix(matrix);
	printf("> Time spent: %f\n", delta); 

	return 0;
}

bool solveTour(Knight k, int it, int matrix[N][N]) {
	if (it == N*N + 1)
		return 1;


	return 0; 
}

