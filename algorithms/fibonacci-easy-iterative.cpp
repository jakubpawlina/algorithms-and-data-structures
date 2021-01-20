// Author: Jakub Pawlina
// Algoritm: Fibonacci Numbers (easy iteration)

#include <bits/stdc++.h>

int fib(int n)
{
	int a = 0, b = 1, c;
	if (n == 0) return a;
	for (int i = 2; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	while (std::cin >> n)
	{
		std::cout << fib(n) << '\n';
	}

	return 0;
}
