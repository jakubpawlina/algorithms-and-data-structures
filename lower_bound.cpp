#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int lower_bound(int array[], int size, int value)
{
	int begin = 0, end = size;
	while (begin < end)
	{
		int midst = begin + ((end - begin) >> 1);
		if (value <= array[midst]) end = midst;
		else begin = midst + 1;
	}
	return (begin == size) ? -1 : begin;
}

int lower_bound_recursive(int array[], int size, int begin, int end, int value)
{
	if (begin > end) return (begin == size) ? -1 : begin;
	int midst = (begin + end) >> 1;
	if (value <= array[midst]) return lower_bound_recursive(array, size, begin, midst - 1, value);
	else return lower_bound_recursive(array, size, midst + 1, end, value);
}

int input[1000006];

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}

	int k;
	std::cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int value;
		std::cin >> value;
		int lower = lower_bound(input, n, value);
		if (lower == -1) std::cout << "-1 ";
		else std::cout << lower + 1 << ' ';
	}

	return 0;
}
