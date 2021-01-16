// Author: Jakub Pawlina
// Algorithm: Euclidean Algorithm (GCD)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int gcd_1(int a, int b)
{
	if (a < b) std::swap(a, b);
	for (int i = b; i >= 1; --i)
	{
		if (!(a % i) && !(b % i)) return i;
	}
	return 1;
}

int gcd_2(int a, int b)
{
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int gcd_3(int a, int b)
{
	while (b)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int gcd_4(int a, int b)
{
	while (b)
	{
		a %= b;
		std::swap(a, b);
	}
	return a;
}

int gcd_5(int a, int b)
{
	return b ? gcd_4(b, a % b) : a;
}

int gcd_6(int a, int b)
{
	if (!a || !b) return a | b;
	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do
	{
		b >>= __builtin_ctz(b);
		if (a > b) a ^= b, b ^= a, a ^= b;
		b -= a;
	} while (b);
	return a << shift;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b;
	std::cin >> a >> b;

	std::cout << gcd_1(a, b) << '\n';
	std::cout << gcd_2(a, b) << '\n';
	std::cout << gcd_3(a, b) << '\n';
	std::cout << gcd_4(a, b) << '\n';
	std::cout << gcd_5(a, b) << '\n';
	std::cout << gcd_6(a, b) << '\n';
	std::cout << std::__gcd(a, b) << '\n';
	// std::cout << std::gcd(a, b) << '\n'; // Since C++17

	return 0;
}
