// Author: Jakub Pawlina
// Algorithm: Shoelace Formula (polygon area)

#include <bits/stdc++.h>

typedef long double num;

struct Point
{
	num x, y;
	Point () {}
	Point (num _x, num _y) : x(_x), y(_y) {}
	Point operator-(const Point& p) const {return Point(x - p.x, y - p.y);}
	num cross_product(const Point& p) const {return x * p.y - y * p.x;}
	num cross_product(const Point& a, const Point &b) const {return (a - *this).cross_product(b - *this);}

	void read()
	{
		std::cin >> x >> y;
	}
};

num shoelace_formula(const std::vector <Point>& vertices)
{
	num area = vertices[vertices.size() - 1].x * vertices[0].y - vertices[vertices.size() - 1].y * vertices[0].x;
	for (size_t i = 1; i < vertices.size(); ++i)
	{
		area += vertices[i - 1].x * vertices[i].y - vertices[i - 1].y * vertices[i].x;
	}
	return fabs(area / 2.);
}

num polygon_area(const std::vector <Point>& vertices)
{
	num area = vertices[vertices.size() - 1].cross_product(vertices[0]);
	for (size_t i = 1; i < vertices.size(); ++i)
	{
		area += vertices[i - 1].cross_product(vertices[i]);
	}
	return fabs(area / 2.);
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	size_t vertices_number;
	std::cin >> vertices_number;

	std::vector <Point> vertices(vertices_number);

	for (size_t i = 0; i < vertices_number; ++i)
	{
		std::cin >> vertices[i].x >> vertices[i].y;
	}

	std::cout << shoelace_formula(vertices) << '\n';
	std::cout << polygon_area(vertices) << '\n';

	return 0;
}
