// Author: Jakub Pawlina
// Algorithm: Sieve of Eratosthenes

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

std::vector <int> sieve(int n)
{
	std::vector <int> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 2; i * i <= n; ++i)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int const n = 100;

	std::vector <int> is_prime = sieve(n);

	for (int i = 0; i <= n; ++i)
	{
		std::cout << i << " is " << (is_prime[i] ? "" : "not ") << "prime.\n";
	}

	return 0;
}
