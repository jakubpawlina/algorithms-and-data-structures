// Author: Jakub Pawlina
// Algorithm: Linear Diophantine Equation

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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &gcd)
{
	gcd = ext_gcd(std::abs(a), std::abs(b), x0, y0);
	if (c % gcd) return false;
	x0 *= c / gcd;
	y0 *= c / gcd;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c;
	std::cin >> a >> b >> c;

	int x0, y0, gcd;

	bool any = false;

	std::cout << a << "x + " << b << "y = " << c << '\n';

	if (!a && !b)
	{
		if (c) any = false;
		else
		{
			std::cout << "IDENTITY EQUATION\n";
			return 0;
		}
	}
	else any = find_any_solution(a, b, c, x0, y0, gcd);

	if (!any)
	{
		std::cout << "NO SOLUTIONS\n";
		return 0;
	}

	std::cout << "x = " << x0 << " + " << b / gcd << "k\n";
	std::cout << "y = " << y0 << " - " << a / gcd << "k\n";

	return 0;
}
