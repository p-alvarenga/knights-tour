#include <string>

void printMatrix(int matrix[N][N]) // [!] need to refactor this
{  
	int max_digit = 0;

	max_digit = static_cast<int>(std::log10(N_MAX)) + 1;
	std::string border = std::string(N * (max_digit + 1) + 1, '-'); 

	printf(".%s.\n|", border.c_str());

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			switch (matrix[i][j]) 
			{
				case 0:
					printf(" %*c", max_digit, C_EMPTY);
					break;
				default:
					printf(" %*i", max_digit, matrix[i][j]);
					break;
			}
		}

		printf(" |\n|");
	}

	printf("\b.%s.\n> Solution for N = %i\n\n", border.c_str(), N);
}
