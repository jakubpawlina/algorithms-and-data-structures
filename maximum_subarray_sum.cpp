// Author: Jakub Pawlina
// Algorithm: Kadane's Algorithm

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int elements_number;
	std::cin >> elements_number;

	int sum = 0, result = 0;

	for (int i = 0; i < elements_number; ++i)
	{
		int element;
		std::cin >> element;
		sum = std::max(element, sum + element);
		result = std::max(result, sum);
	}

	std::cout << result << '\n';

	return 0;
}