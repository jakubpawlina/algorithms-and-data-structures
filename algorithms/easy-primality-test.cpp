#pragma GCC optimize("O3")
#include <bits/stdc++.h>

bool prime(int n)
{
	if (n == 2) return true;
	if (!(n & 1)) return false;
	for (int d = 3; d * d <= n; d += 2)
	{
		if (!(n % d)) return false;
	}
	return true;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;

	if (n == 0 || n == 1) std::cout << "NOT PRIME AND NOT COMPOSITE\n";
	else if (n < 0) std::cout << "NEGATIVE\n";
	else if (prime(n)) std::cout << "PRIME\n";
	else std::cout << "COMPOSITE\n";

	return 0;
}