// Author: Jakub Pawlina
// Algorithm: Interpolation Search

#include <bits/stdc++.h>

int interpolation_search(std::vector <int> data, int key)
{
	int lower = 0, higher = data.size() - 1;
	while (lower <= higher && data[lower] <= key && key <= data[higher])
	{
		if (lower == higher)
		{
			if (data[lower] == key) return lower;
			return -1;
		}

		double fraction = (double) ((higher - lower) / (data[higher] - data[lower]));
		int position = lower + (fraction * (key - data[lower]));

		if (data[position] == key) return position;
		if (data[position] < key) lower = position + 1;
		if (data[position] > key) higher = position - 1;
	}
	return -1;
}

int32_t main()
{
	int elements_number;
	std::cin >> elements_number;

	std::vector <int> data;

	for (int i = 0; i < elements_number; ++i)
	{
		int tmp; std::cin >> tmp;
		data.push_back(tmp);
	}

	int key_number;
	std::cin >> key_number;

	for (int i = 0; i < key_number; ++i)
	{
		int key; std::cin >> key;
		int position = interpolation_search(data, key);
		if (!~position) std::cout << "- ";
		else std::cout << position + 1 << ' ';
	}

	return 0;
}
