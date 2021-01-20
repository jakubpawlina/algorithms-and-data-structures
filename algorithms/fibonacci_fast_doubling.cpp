// Author: Jakub Pawlina
// Algoritm: Fibonacci Numbers (fast doubling)

#include <bits/stdc++.h>

int square(int n)
{
	return n * n;
}

int fib(int n)
{
	if (n <= 2) return 1;
	if (n & 1) return square(fib((n + 1) / 2)) + square(fib((n + 1) / 2 - 1));
	return square(fib(n / 2 + 1)) - square(fib(n / 2 - 1));
}

std::pair <int, int> fib_2(int n)
{
	if (n == 0) return {0, 1};
	auto fk = fib_2(n >> 1);
	int v1 = fk.first * (2 * fk.second - fk.first);
	int v2 = fk.first * fk.first + fk.second * fk.second;
	if (n & 1) return {v2, v1 + v2};
	else return {v1, v2};
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	while (std::cin >> n)
	{
		std::cout << fib(n) << " (" << fib_2(n).first << ")\n";
	}

	return 0;
}
