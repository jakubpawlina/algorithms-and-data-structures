// Author: Jakub Pawlina
// Algorith: Prefix Sum 2D

#include <bits/stdc++.h>

int prefix[1024][1024];

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int columns_number, rows_number;
	std::cin >> columns_number >> rows_number;

	for (int row = 1; row <= rows_number; ++row)
	{
		for (int col = 1; col <= columns_number; ++col)
		{
			int current_element;
			std::cin >> current_element;
			prefix[row][col] = current_element + prefix[row - 1][col] + prefix[row][col - 1] - prefix[row - 1][col - 1];
		}
	}

	int queries_number;
	std::cin >> queries_number;

	for (int i = 0; i < queries_number; ++i)
	{
		int col1, row1, col2, row2;
		std::cin >> col1 >> row1 >> col2 >> row2;
		std::cout << prefix[row2][col2] - prefix[row1 - 1][col2] - prefix[row2][col1 - 1] + prefix[row1 - 1][col1 - 1] << '\n';
	}

	return 0;
}
