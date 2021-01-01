// Author: Jakub Pawlina
// Data Strucure: Find-Union (Disjoint-set)


#pragma GCC optimize("O3")
#include <bits/stdc++.h>

namespace djs
{
  int find(int *parent, int element)
  {
    if (parent[element] != element)
    {
      parent[element] = find(parent, parent[element]);
    }
    return parent[element];
  }

  void unify(int *parent, int *rank, int first_element, int second_element)
  {
    int first_parent = find(parent, first_element);
    int second_parent = find(parent, second_element);
    if (rank[first_parent] < rank[second_parent])
    {
      parent[first_parent] = second_parent;
    }
    else
    {
      parent[second_parent] = first_parent;
    }
    if (rank[first_parent] == rank[second_parent])
    {
      ++rank[first_parent];
    }
  }
}

int32_t main()
{
  std::ios_base::sync_with_stdio(false);

  int elements_number = 10;

  int parent[elements_number + 1];
  int rank[elements_number + 1];

  for (int i = 1; i <= elements_number; ++i)
  {
    parent[i] = i;
    rank[i] = 0;
  }

  std::string operation_type;
  while (std::cin >> operation_type)
  {
    if (operation_type == "UNION")
    {
      int first_element, second_element;
      std::cin >> first_element >> second_element;
      djs::unify(parent, rank, first_element, second_element);
    }
    else if (operation_type == "FIND")
    {
      int element;
      std::cin >> element;
      std::cout << djs::find(parent, element) << '\n';
    }
    else if (operation_type == "SHOW")
    {
      std::cout << "ELEMENT: ";
      for (int i = 1; i <= elements_number; ++i)
      {
        std::cout << i << " \n"[i == elements_number];
      }
      std::cout << "PARENT:  ";
      for (int i = 1; i <= elements_number; ++i)
      {
        std::cout << djs::find(parent, i) << " \n"[i == elements_number];
      }
    }
    else if (operation_type == "STOP")
    {
      return 0;
    }
  }

  return 0;
}
