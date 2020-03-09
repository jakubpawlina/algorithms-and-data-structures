#include <bits/stdc++.h>

void kmp(std::string text, std::string pattern)
{
	if (!text.size() || !pattern.size())
	{
		std::cout << "-1\n";
		return;
	}

	int failure[pattern.size()];
	std::fill(failure, failure + pattern.size(), -1);

	for (int begin = -1, end = 1; end < pattern.size(); ++end)
	{
		while (begin != -1 && pattern[begin + 1] != pattern[end])
			begin = failure[begin];
		if (pattern[begin + 1] == pattern[end])
			failure[end] = ++begin;
	}

	int position = -1;
	bool output = false;

	for (int i = 0; i < text.size(); ++i)
	{
		while (position != -1 && text[i] != pattern[position + 1])
			position = failure[position];
		if (text[i] == pattern[position + 1])
			++position;
		if (position == pattern.size() - 1)
		{
			std::cout <<  i - position + 1 << ' ';
			output = true;
		}
	}

	if (!output)
		std::cout << -1;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string text;
	std::cin >> text;

	std::string pattern;
	std::cin >> pattern;

	kmp(text, pattern);

	return 0;
}
