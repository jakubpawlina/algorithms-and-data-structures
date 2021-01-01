// Author: Jakub Pawlina
// Algorithm: Fast Power modulo

#include <bits/stdc++.h>

long long fast_power(int base, unsigned int exponent, int modulo = INT_MAX)
{
	long long result = 1;

	base %= modulo;

	while (exponent > 0)
	{
		if (exponent & 1)
		{
			result = (result * base) % modulo;
		}
		exponent >>= 1;
		base = (base * base) % modulo;
	}

	return result;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int base, exponent, modulo;
	std::cin >> base >> exponent >> modulo;
	std::cout << fast_power(base, exponent, modulo) << '\n';

	return 0;
}
