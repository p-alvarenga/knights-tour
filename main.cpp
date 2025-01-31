#include <stdio.h>
#include <time.h>

#include "constants.h"
#include "Pos.h"
#include "Knight.h"

void printMatrix(short int matrix[N][N]);
bool solveTour(Knight k, int it, short int matrix[N][N]);
bool availableMove(Pos p, short int matrix[N][N]);

int main(void) {
	short int matrix[N][N] = { 0 };

	Knight k;
	k.pos.set(INIT_X, INIT_Y);
	
	matrix[INIT_X][INIT_Y] = 1;

	clock_t begin = clock();
	solveTour(k, 2, matrix);
	clock_t end = clock();

	matrix[1][2] = 60;
	printMatrix(matrix);
	printf("> Time spent: %f\n", (double)(end - begin) / CLOCKS_PER_SEC); 

	return 0;
}

bool solveTour(Knight k, int it, short int matrix[N][N]) {
	static Pos p; // helper
	Knight k_jump;

	if (it == N*N + 1) {
		return 1;
	}

	for (int i = 0; i < N; i++) {
		p = k.move(i);

		if (p.validate() && matrix[p.x][p.y] == 0) {
			matrix[p.x][p.y] = it;
			k_jump.pos = p;

			if (solveTour(k_jump, it + 1, matrix)) {
				return 1;
			} else {
				matrix[k_jump.pos.x][k_jump.pos.y] = 0;
				i += 3;
			}
		}
  }

  return 0;
}

void printMatrix(short int matrix[N][N]) {
	printf(".-------------------------.\n|");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] > 9 ? printf(" ") : printf("  ");

			switch (matrix[i][j]) {
			case 0:
				printf(C_EMPTY);
				break;
			case 99:
				printf(" #"); // DEBUGGING
				break;
			default:
				printf("%i", matrix[i][j]);
				break;
			}
		}
		printf(" |\n|");
	}
	printf("\b.-------------------------.\n");

	return;
}
