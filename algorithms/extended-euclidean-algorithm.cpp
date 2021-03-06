// Author: Jakub Pawlina
// Algorithm: Extended Euclidean Algorithm

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int ext_gcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int gcd = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return gcd;
}

std::pair <int, int> ext_gcd_2(int a, int b)
{
	if (b == 0) return {1, 0};
	std::pair <int, int> p = ext_gcd_2(b, a % b);
	return (std::pair <int, int> {p.second, p.first - (a / b) * p.second});
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b;
	std::cin >> a >> b;

	int x, y;
	int gcd = ext_gcd(a, b, x, y);

	std::cout << a << " * " << x << " + " << b << " * " << y << " = gcd(" << a << ", " << b << ") = " << gcd << '\n';

	return 0;
}
