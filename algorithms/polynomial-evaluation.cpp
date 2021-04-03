// Author: Jakub Pawlina
// Algorithm: Polynomial Evaluation

#include <bits/stdc++.h>

int64_t evaluate_polynomial(unsigned polynomial_degree, std::vector <int> &coefficients, int x)
{
	int64_t result = coefficients[0];
	for (unsigned i = 1; i <= polynomial_degree; ++i)
	{
		result = result * x + coefficients[i];
	}
	return result;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned polynomial_degree = 5;
	std::vector <int> coefficients = {7, 0, 17, 8, 2, 5};
	// P(x) = 7x^5 + 0x^4 + 17x^3 + 8x^2 + 2x + 5

	std::cout << evaluate_polynomial(polynomial_degree, coefficients, 17) << '\n';

	return 0;
}
