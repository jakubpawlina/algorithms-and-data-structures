// Author: Jakub Pawlina
// Algorithm: Counting graph components number (using DFS)

#include <bits/stdc++.h>

std::vector <int> graph[1000100];
std::array <bool, 1000100> visited = {0};

void DFS(int vertex);

int32_t main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int vertices_number; std::cin >> vertices_number;
  int edges_number; std::cin >> edges_number;

  for (int i = 0; i < edges_number; ++i)
  {
    int begin; std::cin >> begin;
    int end; std::cin >> end;
    graph[begin].push_back(end);
    graph[end].push_back(begin);
  }

  int components_number = 0;
  for (int i = 1; i <= vertices_number; ++i)
  {
    if (!visited[i])
    {
      DFS(i);
      ++components_number;
    }
  }

  std::cout << components_number - 1 << '\n';

  return 0;
}

void DFS(int vertex)
{
  visited[vertex] = 1;
  for (size_t i = 0; i < graph[vertex].size(); ++i)
  {
    if (!visited[graph[vertex][i]])
    {
      DFS(graph[vertex][i]);
    }
  }
}
