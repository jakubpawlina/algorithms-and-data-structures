// Author: Jakub Pawlina
// Algorithm: Knapsack Problem

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

struct Item
{
	int weight;
	int value;

	void read()
	{
		std::cin >> value >> weight;
	}
};

int result[2][10005];

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int knapsack_size;
	std::cin >> knapsack_size;

	int items_number;
	std::cin >> items_number;

	for (int item_nr = 0; item_nr < items_number; ++item_nr)
	{
		Item item;
		item.read();
		for (int volume = 0; volume <= knapsack_size; ++volume)
		{
			if (volume < item.weight)
			{
				result[item_nr % 2][volume] = result[(item_nr + 1) % 2][volume];
			}
			else
			{
				result[item_nr % 2][volume] = std::max(result[(item_nr + 1) % 2][volume - item.weight] + item.value, result[(item_nr + 1) % 2][volume]);
			}
		}
	}

	if (knapsack_size && items_number) std::cout << std::max(result[0][knapsack_size], result[1][knapsack_size]) << '\n';
	else std::cout << "0\n";

	return 0;
}