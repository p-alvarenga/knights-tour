#ifndef PRINT_SOLUTION__H__
#define PRINT_SOLUTION__H__

#include <string>

void printSolution(int matrix[N][N], double time_spent) // [!] need to refactor this
{  
	int max_digit = 0;

	max_digit = static_cast<int>(std::log10(N_MAX)) + 1;
	std::string border = std::string(N * (max_digit + 1) + 1, '='); 

	printf("- Solution for N = %i\n*%s*\n|", N, border.c_str());

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			printf(" %*i", max_digit, matrix[i][j]);
		}

		printf(" |\n|");
	}

	printf("\b*%s*\n\n- Time spent: %f sec\n\n", border.c_str(), time_spent);
}

#endif
