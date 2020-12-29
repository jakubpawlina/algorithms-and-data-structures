#pragma GCC optimize("O3")
#include <bits/stdc++.h>

struct Event
{
	int begin;
	int end;

	bool operator<(const Event &e)
	{
		if (end != e.end) return end < e.end;
		else return begin < e.begin;
	}
};

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned int events_number;
	std::cin >> events_number;

	std::vector <Event> events(events_number);

	for (size_t i = 0; i < events_number; ++i)
	{
		std::cin >> events[i].begin >> events[i].end;
	}

	std::sort(events.begin(), events.end());

	int max_possible = 0;

	Event selected = {-1, -1};

	for (size_t i = 0; i < events_number; ++i)
	{
		if (events[i].begin >= selected.end)
		{
			selected = events[i];
			++max_possible;
		}
	}

	std::cout << max_possible << '\n';

	return 0;
}
