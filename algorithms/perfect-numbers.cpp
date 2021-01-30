// Author: Jakub Pawlina
// Algorithm: Perfect Numbers in range

#include <bits/stdc++.h>

bool prime(int64_t n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (!(n & 1)) return false;
	for (int d = 3; d * d <= n; d += 2)
	{
		if (!(n % d)) return false;
	}
	return true;
}

void find_perfects(std::vector <int64_t>& perfects)
{
	std::vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	for (size_t i = 0; i < primes.size(); ++i)
	{
		int nth = primes[i];
		int64_t sum = ((1 << nth) - 1);
		if (prime(sum)) perfects.emplace_back(sum * (1 << (nth - 1)));
	}
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector <int64_t> perfects;
	find_perfects(perfects);

	int64_t begin, end;
	std::cin >> begin >> end; // end <= 10^18

	bool output = false;

	for (size_t i = 0; i < perfects.size(); ++i)
	{
		if (begin <= perfects[i] && perfects[i] <= end)
		{
			output = true;
			std::cout << perfects[i] << ' ';
		}
	}

	if (output) std::cout << '\n';
	else std::cout << "No perfect numbers in given range!\n";

	return 0;
}
