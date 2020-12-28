// Author: Jakub Pawlina
// Algorithm: Bitonic Point

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int bitonic_point(std::vector <int> bitonic_sequence)
{
	int position = -1;
	for (int i = bitonic_sequence.size() - 1; i >= 1; i /= 2)
	{
		while (bitonic_sequence[i + position] < bitonic_sequence[i + position + 1])
		{
			position += i;
		}
	}
	return position + 1;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector <int> bitonic_sequence{5, 7, 35, 64, 1024, 1025, 1023, 513, 255, 121, 8, 3, 2, 1};

	for (size_t i = 0; i < bitonic_sequence.size(); ++i)
	{
		std::cout << "[" << i << "] : " << bitonic_sequence[i] << '\n';
	}

	int position = bitonic_point(bitonic_sequence);

	std::cout << "Bitonic Point (" << bitonic_sequence[position] << ") at position " << position << '\n';

	return 0;
}
