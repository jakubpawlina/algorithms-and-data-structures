// Author: Jakub Pawlina
// Algorithm: Binsearch

#include <bits/stdc++.h>

bool binsearch(std::vector <int> number, int sought)
{
  int begin = 0, end = number.size();
  while (number[begin] <= sought)
  {
    int midst = (begin + end) >> 1;
    if (number[midst] == sought)
    {
      return true;
    }
    if (sought < number[midst])
    {
      end = midst - 1;
    }
    else
    {
      begin = midst + 1;
    }
  }
  return false;
}

int binsearch_position(std::vector <int> number, int sought)
{
  int begin = 0, end = number.size();
  while (number[begin] <= sought)
  {
    int midst = (begin + end) >> 1;
    if (number[midst] == sought)
    {
      return midst;
    }
    if (sought < number[midst])
    {
      end = midst - 1;
    }
    else
    {
      begin = midst + 1;
    }
  }
  return -1;
}

int32_t main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  std::vector <int> number {1, 2, 4, 7, 9, 10, 1000, 1996, 2002, 2501, 9999, 10000};
  for (int i = 1; i < 12; ++i)
  std::cout << i << ' ' << binsearch(number, i) << ' ' << binsearch_position(number, i) << '\n';
  
  return 0;
}
