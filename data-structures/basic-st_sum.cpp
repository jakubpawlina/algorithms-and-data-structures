// Author: Jakub Pawlina
// Algorithm: Basic segment tree (sum on interval)

#include <bits/stdc++.h>

constexpr int base = (1 << 18);

int segment_tree[base << 1];

void init();
int query(int begin, int end);
void update(int position, int value);
void answer_queries();

int32_t main()
{
	init();

	answer_queries();

	return 0;
}

void init()
{
	int segment_tree_size;
	std::cin >> segment_tree_size;

	for (int i = base; i < base + segment_tree_size; ++i)
	{
		std::cin >> segment_tree[i];
	}

	for (int i = base - 1; i > 0; --i)
	{
		segment_tree[i] = segment_tree[i << 1] + segment_tree[(i << 1) + 1];
	}
}

int query(int begin, int end)
{
	begin += (base - 1);
	end += (base - 1);
	if (begin == end) return segment_tree[begin];

	int64_t result = segment_tree[begin] + segment_tree[end];
	while (begin + 1 < end)
	{
		if (!(begin & 1)) result += (int64_t)segment_tree[begin + 1];
		if (end & 1) result += (int64_t)segment_tree[end - 1];
		begin >>= 1; end >>= 1;
	}
	return result;
}

void update(int position, int value)
{
	position = base + position - 1;
	segment_tree[position] = value;
	while (position >>= 1)
	{
		segment_tree[position] = segment_tree[position << 1] + segment_tree[(position << 1) + 1];
	}
}

void answer_queries()
{
	std::string operation;
	while (std::cin >> operation)
	{
		if (operation == "UPDATE")
		{
			int position, value;
			std::cin >> position >> value;
			update(position, value);
		}
		else if (operation == "QUERY")
		{
			int begin, end;
			std::cin >> begin >> end;
			std::cout << query(begin, end) << '\n';
		}
	}
}
