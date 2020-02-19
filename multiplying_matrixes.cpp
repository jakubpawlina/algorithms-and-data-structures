// Author: Jakub Pawlina
// Algorithm: Multiplying matrixes

#include <bits/stdc++.h>

struct Matrix
{
	int columns;
	int rows;
	int values[100][100];
};

Matrix multiply(Matrix first_matrix, Matrix second_matrix)
{
	Matrix result_matrix;
	result_matrix.rows = first_matrix.rows;
	result_matrix.columns = second_matrix.columns;

	if (first_matrix.columns != second_matrix.rows)
	{
		std::cout << "Cannot multiply!\n";
		return result_matrix;
	}

	for (size_t i = 0; i < result_matrix.rows; ++i)
	{
		for (size_t j = 0; j < result_matrix.columns; ++j)
		{
			int result = 0;
			for (size_t k = 0; k < first_matrix.columns; ++k)
			{
				result += first_matrix.values[i][k] * second_matrix.values[k][j];
			}
				result_matrix.values[i][j] = result;
		}
	}

	return result_matrix;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
  
	Matrix first_matrix;
	std::cin >> first_matrix.rows >> first_matrix.columns;
	for (size_t i = 0; i < first_matrix.rows; ++i)
	{
		for (size_t j = 0; j < first_matrix.columns; ++j)
		{
			std::cin >> first_matrix.values[i][j];
		}
	}

	Matrix second_matrix;
	std::cin >> second_matrix.rows >> second_matrix.columns;
	for (size_t i = 0; i < second_matrix.rows; ++i)
	{
		for (size_t j = 0; j < second_matrix.columns; ++j)
		{
			std::cin >> second_matrix.values[i][j];
		}
	}

	Matrix result_matrix = multiply(first_matrix, second_matrix);

	for (size_t i = 0; i < result_matrix.rows; ++i)
	{
		for (size_t j = 0; j < result_matrix.columns; ++j)
		{
			std::cout << result_matrix.values[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}


/*
SAMPLE

Input:

2 3
2 1 3
-1 4 0

3 3
1 3 2
-2 0 1
5 -3 2


Output:

15 -3 11
-9 -3 2

*/
