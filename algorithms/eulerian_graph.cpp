// Author: Jakub Pawlina
// Algorithm: Eulerian Graph determining

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

std::vector <int> graph[1000006];
std::array <bool, 1000006> visited;

void dfs(int vertex, int &size)
{
	visited[vertex] = true;
	for (auto &v : graph[vertex])
	{
		if (!visited[v]) dfs(v, size);
	}
	++size;
}

bool eulerian(int vertices_number)
{
	for (auto &v : graph)
	{
		if (v.size() & 1)
		{
			return 0;
		}
	}

	int component_size = 0;
	dfs(1, component_size);
	if (component_size == vertices_number)
	{
		return 1;
	}

	return 0;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int vertices_number;
	std::cin >> vertices_number;

	int edges_number;
	std::cin >> edges_number;

	for (int i = 0; i < edges_number; ++i)
	{
		int begin, end;
		std::cin >> begin >> end;
		graph[begin].push_back(end);
		graph[end].push_back(begin);
	}

	if (eulerian(vertices_number)) std::cout << "EULERIAN GRAPH\n";
	else std::cout << "NOT EULERIAN GRAPH\n";

	return 0;
}
