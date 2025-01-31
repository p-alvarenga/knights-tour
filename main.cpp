#include <stdio.h>
#include <time.h>

#define N 8 // Matrix Size [N x N]
#define C_EMPTY "."

#include "./Knight.h"
#include "./Pos.h"

#define INIT_X 0
#define INIT_Y 0

void printMatrix(short int matrix[N][N]);
bool solveTour(Knight &k, int it, short int matrix[N][N]);
bool availableMove(Pos p, short int matrix[N][N]);

int main(void) {
	short int matrix[N][N] = { 0 };

	Knight k;
	k.pos.set(INIT_X, INIT_Y);
	
	matrix[INIT_X][INIT_Y] = 1;

	clock_t begin = clock();
	solveTour(k, 2, matrix);
	clock_t end = clock();

	printMatrix(matrix);
	printf("Time spent: %f", (double)(end - begin) / CLOCKS_PER_SEC);

	return 0;
}

bool solveTour(Knight &k, short int it, short int matrix[N][N]) {
	static Pos p;
	Knight k_jump;

	if (it == N*N) {
		return 1;
	}

	for (short int i = 0; i < N; i++) {
		p = k.move(i);

		if (p.validate() && matrix[p.x][p.y] == 0) {
			matrix[p.x][p.y] = it;
			k_jump.pos = p;

			if (solveTour(k_jump, it + 1, matrix)) {
				return 1;
			} else {
				matrix[k_jump.pos.x][k_jump.pos.y] = 0;
				i++;
			}
		}
  }

  return 0;
}

void printMatrix(short int matrix[N][N]) {
	for (short int i = 0; i < N; i++) {
		for (short int j = 0; j < N; j++) {
			matrix[i][j] > 9 ? printf(" ") : printf("  ");

			switch (matrix[i][j]) {
			case 0:
				printf(C_EMPTY);
				break;
			case 99:
				printf(" #");
				break;
			default:
				printf("%i", matrix[i][j]);
				break;
			}
		}
		printf("\n");
	}
	printf("\n");

	return;
}
