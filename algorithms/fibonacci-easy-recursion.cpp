// Author: Jakub Pawlina
// Algoritm: Fibonacci Numbers (easy recursion)

#include <bits/stdc++.h>

int fib_r(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return fib_r(n - 1) + fib_r(n - 2);
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	while (std::cin >> n)
	{
		std::cout << fib_r(n) << '\n';
	}

	return 0;
}
