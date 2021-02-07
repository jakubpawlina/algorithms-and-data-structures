// Author: Jakub Pawlina
// Algorithm: Clockwise placement of a segment

#include <bits/stdc++.h>

struct Point
{
	double x, y;
};

struct DirectedSegment
{
	Point p1, p2;
};

double cross_product(DirectedSegment s1, DirectedSegment s2)
{
	double x1y2 = (s1.p2.x - s1.p1.x) * (s2.p2.y - s2.p1.y);
	double x2y1 = (s2.p2.x - s2.p1.x) * (s1.p2.y - s1.p1.y);
	return x1y2 - x2y1;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Point p0 {7.20, 8.55};
	Point p1 {15.73, 24.24};
	Point p2 {19.19, 22.23};

	DirectedSegment s1 = {p0, p1};
	DirectedSegment s2 = {p0, p2};

	std::cout << "PLACEMENT OF S_2 AGAINST S_1:\n";

	if (cross_product(s1, s2) < 0) std::cout << "ROTATED CLOCKWISE\n";
	else if (cross_product(s1, s2) > 0) std::cout << "ROTATED ANTICLOCKWISE\n";
	else std::cout << "THE SAME DIRECTION\n";

	return 0;
}
