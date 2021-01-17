// Author: Jakub Pawlina
// Algorithm: Sum on interval (basic segment tree)

#include <bits/stdc++.h>

constexpr int base = (2 << 18);

int segment_tree[base << 1];

void read_base(int segment_tree_size);
void calculate_tree();
void init(int segment_tree_size);
int query(int begin, int end);
void answer_queries(int queries_number);
void update(int position, int value);

int32_t main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int segment_tree_size; std::cin >> segment_tree_size;
  init(segment_tree_size);

  update(3, 3);

  int queries_number; std::cin >> queries_number;
  answer_queries(queries_number);

  return 0;
}

void read_base(int segment_tree_size)
{
  for (int i = base; i < base + segment_tree_size; ++i)
  {
    std::cin >> segment_tree[i];
  }
}

void calculate_tree()
{
  for (int i = base - 1; i > 0; --i)
  {
    segment_tree[i] = segment_tree[2 * i] + segment_tree[2 * i + 1];
  }
}

void init(int segment_tree_size)
{
  read_base(segment_tree_size);
  calculate_tree();
}

int query(int begin, int end)
{
  begin += base - 1;
  end += base - 1;
  long long result = 0;
  if (begin == end) return segment_tree[begin];
  result = segment_tree[begin] + segment_tree[end];
  while (begin / 2 != end / 2)
  {
    if (!(begin & 1)) result += segment_tree[begin + 1];
    if (end & 1) result += segment_tree[end - 1];
    begin /= 2; end /= 2;
  }
  return result;
}

void answer_queries(int queries_number)
{
  while (queries_number--)
  {
    int begin, end; std::cin >> begin >> end;
    std::cout << query(begin, end) << '\n';
  }
}

void update(int position, int value)
{
  position = base + position - 1;
  segment_tree[position] = value;
  while (position)
  {
    position >>= 1;
    segment_tree[position] = segment_tree[position << 1] + segment_tree[(position << 1) + 1];
  }
}
