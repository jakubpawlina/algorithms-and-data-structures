// Author: Jakub Pawlina
// Algorithm: Convex Hull (using Graham's Scan)

#include <bits/stdc++.h>

struct Point
{
	double x;
	double y;
};

bool cmp(Point p1, Point p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool uniq(Point p1, Point p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool clockwise(Point p1, Point p2, Point p3)
{
	return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) < 0;
}

bool counterclockwise(Point p1, Point p2, Point p3)
{
	return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) > 0;
}

std::vector <Point> convex_hull(std::vector <Point> &points)
{
	if (points.size() == 1) return points;
	std::sort(points.begin(), points.end(), &cmp);
	Point first_point = points[0], last_point = points.back();
	std::vector <Point> up, down;
	up.push_back(first_point);
	down.push_back(first_point);
	for (size_t i = 1; i < points.size(); ++i)
	{
		if (i == points.size() - 1 || clockwise(first_point, points[i], last_point))
		{
			while (up.size() >= 2 && !clockwise(up[up.size() - 2], up[up.size() - 1], points[i])) up.pop_back();
			up.push_back(points[i]);
		}
		if (i == points.size() - 1 || counterclockwise(first_point, points[i], last_point))
		{
			while (down.size() >= 2 && !counterclockwise(down[down.size() - 2], down[down.size() - 1], points[i])) down.pop_back();
			down.push_back(points[i]);
		}
	}
	std::vector <Point> ch;
	for (size_t i = 0; i < up.size(); ++i) ch.push_back(up[i]);
	for (size_t i = down.size() - 2; i > 0; --i) ch.push_back(down[i]);
	return ch;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int points_number;

	while (std::cin >> points_number && points_number != 0)
	{
		std::vector <Point> points;
		for (int i = 0; i < points_number; ++i)
		{
			Point p;
			std::cin >> p.x >> p.y;
			points.push_back(p);
		}
		std::sort(points.begin(), points.end(), cmp);
		points.erase(std::unique(points.begin(), points.end(), uniq), points.end());
		std::vector <Point> ch = convex_hull(points);
		std::cout << ch.size() << '\n';
		for (auto & point : ch) std::cout << point.x << ' ' << point.y << '\n';
	}

	return 0;
}
