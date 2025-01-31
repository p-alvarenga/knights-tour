#include "constants.h"
#include "Knight.h"
#include "Pos.h"

bool validateTour(short int matrix[N][N]) {
	// find init point 
	bool exist_init = 0; 

	Pos init;
	Knight k; 

	for (int i{0}; i < N; i++) {
		for (int j{0}; j < N; j++) {
			if (matrix[i][j] == 1) {
				exist_init = 1;
				init.set(i, j);
			}

			if (matrix[i][j] < 0 || matrix[i][j] > N*N) {
				return 0;
			}
		}
	}

	if (!exist_init) {
		printf("\n");
		return 0; 
	}

	return 1;
}
