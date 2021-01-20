// Author: Jakub Pawlina
// Algorith: Prefix Sum 1D

#include <bits/stdc++.h>

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned elements_number;
	std::cin >> elements_number;

	std::vector <int> prefix_sum(elements_number + 1);
	prefix_sum[0] = 0;

	for (size_t i = 1; i <= elements_number; ++i)
	{
		int current_element;
		std::cin >> current_element;
		prefix_sum[i] = prefix_sum[i - 1] + current_element;
	}

	unsigned queries_number;
	std::cin >> queries_number;

	for (unsigned i = 0; i < queries_number; ++i)
	{
		unsigned begin, end;
		std::cin >> begin >> end;
		begin = std::max(begin, (unsigned)1);
		end = std::min(end, elements_number);
		std::cout << prefix_sum[end] - prefix_sum[begin - 1] << '\n';
	}

	return 0;
}
