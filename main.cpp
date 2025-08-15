#include <stdio.h>
#include <time.h>
#include <cmath>

#include "include/constants.h"
#include "include/knight.h"
#include "include/tour.h"
#include "include/print-solution.h"

int main(void) 
{
	Tour tour;	

	printf("\n~ Solving for N = %i | OPT_MV = %i ~\n\n", N, OPT_MV);

	clock_t begin = clock();
	tour.solve(Knight());
	clock_t end = clock();

	printSolution(tour.matrix, (double)(end - begin)/CLOCKS_PER_SEC);

	return 0;
}
