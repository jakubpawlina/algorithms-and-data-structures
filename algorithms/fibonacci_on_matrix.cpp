// Author: Jakub Pawlina
// Algorithm: Computing Fibonacci numbers using matrix

#include <bits/stdc++.h>

unsigned long long int fibonacci(int n)
{
  unsigned long long int matrix[2][2];
  matrix[0][0] = 1;
  matrix[0][1] = 1;
  matrix[1][0] = 1;
  matrix[1][1] = 0;
  unsigned long long int result[2][2];
  result[0][0] = 1;
  result[0][1] = 1;
  result[1][0] = 1;
  result[1][1] = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    unsigned long long int r00 = result[0][0], r01 = result[0][1], r10 = result[1][0], r11 = result[1][1];
    result[0][0] = r00 * matrix[0][0] + r01 * matrix[1][0];
    result[0][1] = r00 * matrix[0][1] + r01 * matrix[1][1];
    result[1][0] = r10 * matrix[0][0] + r11 * matrix[1][0];
    result[1][1] = r10 * matrix[0][1] + r11 * matrix[1][1];
  }
  return result[1][1];
}

int32_t main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n; std::cin >> n;
  std::cout << fibonacci(n) << '\n';

  return 0;
}
