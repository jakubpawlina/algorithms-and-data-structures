// Author: Jakub Pawlina
// Algorith: Newton-Raphson square root finding

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

double newton_raphson(double n, const double epsilon)
{
	double a = 1., b = n;
	while (fabs(a - b) >= epsilon)
	{
		a = (a + b) / 2.;
		b = n / a;
	}
	return a;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	const double epsilon = 1e-9;

	std::cout.precision(10);
	for (double i = 0.1; i < 32.1; i += 0.1)
	{
		std::cout << "sqrt(" << i << ") = " << newton_raphson(i, epsilon) << '\n';
	}

	return 0;
}
