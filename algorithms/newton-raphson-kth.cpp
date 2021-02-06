// Author: Jakub Pawlina
// Algorith: Newton-Raphson root finding

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

/* Find n ^ (1 / k) */
double newton_raphson(double k, double n, const double epsilon)
{
	unsigned iter = 0;
	double x1 = 1., x0 = n;
	while (fabs(x0 - x1) >= epsilon)
	{
		x0 = x1;
		x1 = x0 - (pow(x0, k) - n) / (k * pow(x0, k - 1));
		if (++iter > 50) break;
	}
	return x1;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	double k, n;
	const double epsilon = 1e-9;
	std::string precision;

	while (std::cin >> k >> n >> precision)
	{
		std::cout << std::fixed << std::setprecision(precision.size() - 2) << newton_raphson(k, n, epsilon) << '\n';
	}

	return 0;
}