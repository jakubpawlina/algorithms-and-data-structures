// Author: Jakub Pawlina
// Algorithm: Turn Direction using Dot Product

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

struct Point
{
  double x;
  double y;
};

struct Vector
{
  double x;
  double y;
};

long double dot_product(Vector vector1, Vector vector2)
{
  return vector1.x * vector2.y - vector1.y * vector2.x;
}

void turn_direction(std::vector <Point> coordinates)
{
  for (int i = 2; i < coordinates.size(); ++i)
  {
    Vector vector1, vector2;

    vector1.x = coordinates[i - 1].x - coordinates[i - 2].x;
    vector1.y = coordinates[i - 1].y - coordinates[i - 2].y;

    vector2.x = coordinates[i].x - coordinates[i - 1].x;
    vector2.y = coordinates[i].y - coordinates[i - 1].y;

    if (dot_product(vector1, vector2) < 0)
    {
      std::cout << "RIGHT\n";
    }
    else
    {
      std::cout << "LEFT\n";
    }
  }
}

int32_t main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::vector <Point> coordinates;

  Point point;
  while (std::cin >> point.x)
  {
    std::cin >> point.y;
    coordinates.push_back(point);
  }

  turn_direction(coordinates);

  return 0;
}
