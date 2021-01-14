// Author: Jakub Pawlina
// Algorithm: Grid paths extrema

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int grid[1024][1024];
int max[1024][1024];
int min[1024][1024];

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int grid_size;
	std::cin >> grid_size;

	for (int i = 1; i <= grid_size; ++i)
	{
		for (int j = 1; j <= grid_size; ++j)
		{
			std::cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= grid_size; ++i)
	{
		for (int j = 1; j <= grid_size; ++j)
		{
			max[i][j] = std::max(max[i][j - 1], max[i - 1][j]) + grid[i][j];
			min[i][j] = std::min(min[i][j - 1], min[i - 1][j]) + grid[i][j];
		}
	}

	std::cout << "Max sum: " << max[grid_size][grid_size] << '\n';
	std::cout << "Min sum: " << min[grid_size][grid_size] << '\n';

	return 0;
}
