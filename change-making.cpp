// Author: Jakub Pawlina
// Algorithm: Change-making problem

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int minimum_banknotes(int denominations[], int denominations_number, int withdrawal)
{
	int result[withdrawal + 1];
	result[0] = 0;

	for (int i = 1; i <= withdrawal; ++i) result[i] = INT_MAX;

	for (int amount = 1; amount <= withdrawal; ++amount)
	{
		for (int denomination = 0; denomination < denominations_number; ++denomination)
		{
			if (denominations[denomination] <= amount)
			{
				int current_result = result[amount - denominations[denomination]];
				if (current_result != INT_MAX && current_result + 1 < result[amount])
				{
					result[amount] = current_result + 1;
				}
			}
		}
	}

	return result[withdrawal];
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int denominations_number;
	std::cin >> denominations_number;

	int denominations[denominations_number];

	for (int i = 0; i < denominations_number; ++i)
	{
		std::cin >> denominations[i];
	}

	int withdrawal;
	std::cin >> withdrawal;

	int result = minimum_banknotes(denominations, denominations_number, withdrawal);

	if (result == INT_MAX) std::cout << "-1\n";
	else std::cout << result << '\n';

	return 0;
}