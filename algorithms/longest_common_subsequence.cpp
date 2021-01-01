// Author: Jakub Pawlina
// Algorithm: LCS (Longest Common Subsequence)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

std::string LCS(std::string first, std::string second)
{
	int lcs_length[first.length() + 1][second.length() + 1];

	for (int i = 0; i <= first.length(); ++i)
	{
		for (int j = 0; j <= second.length(); ++j)
		{
			if (!i || !j)
			{
				lcs_length[i][j] = 0;
			}
			else if (first[i - 1] == second[j - 1])
			{
				lcs_length[i][j] = lcs_length[i - 1][j - 1] + 1;
			}
			else
			{
				lcs_length[i][j] = std::max(lcs_length[i - 1][j], lcs_length[i][j - 1]);
			}
		}
	}

	int index = lcs_length[first.length()][second.length()];

	std::string lcs = "";

	int i = first.length();
	int j = second.length();
	while (i > 0 && j > 0)
	{
		if (first[i - 1] == second[j - 1])
		{
			lcs = first[i - 1] + lcs;
			i--; j--;
		}
		else if (lcs_length[i - 1][j] > lcs_length[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	return lcs;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	std::string first;
	std::cin >> first;
	std::string second;
	std::cin >> second;

	std::string result = LCS(first, second);

	std::cout << result.length() << '\n';
	std::cout << result << '\n';

	return 0;
}
