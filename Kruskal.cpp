#include <fstream>
#include <sstream>
#include <iostream>
struct Edge
{
   int u;
   int v;
   int w;
};

template <typename T>
void swap (T & left, T & right)
{
  T temp = left;
  left = right;
  right = temp;
}

int partion(Edge edge[], int left, int right)
{
  int pos = left;
  for (int index = left + 1; index < right + 1; ++index)
  {
    if (edge[index].w < edge[left].w)
    {
      swap(edge[++pos], edge[index]);
    }
  }
  swap(edge[left], edge[pos]);
  return pos;
}

void quick_sort(Edge edge[],int left, int right)
{
  if (left > right)
    return;
  int pos = partion(edge, left, right);
  quick_sort(edge, left, pos - 1);
  quick_sort(edge, pos + 1, right);
}

int get_leader(int index, int leader[])
{
  if(leader[index] == index)
  {
    return index;
  }
  else
  {
    return get_leader(leader[index], leader);
  }
}
int merge(int left, int right, int leader[])
{
  int lead_left = get_leader(left, leader);
  int lead_right = get_leader(right, leader);
  if (lead_left != lead_right)
  {
    leader[lead_right] = lead_left;
    return 1;
  }
  return 0;
}

void load_data(Edge edge[])
{
  std::ifstream fin("data.txt");
  std::string number;
  int curl = 0;
  while (getline(fin, number))
  {
    std::istringstream ss(number);
    int u,v,w;
    ss >> edge[curl].u >> edge[curl].v >> edge[curl].w;
    ++ curl;
  }
}

int main(int argc,char ** argv)
{
  int i, n = 6, m = 9;
  Edge edge[9];
  load_data(edge);
  quick_sort(edge, 0, 8);
  for (int index = 0; index < 9; index++)
  {
    std::cout << edge[index].u << " "<< edge[index].v << " "<< edge[index].w;
    std::cout <<std::endl;
  }
  int * leader = new int[n]();
  for (int index = 0; index < n; ++index)
  {
    leader[index] = index;
  }
  std::cout << std::endl;
  int count = 0;
  int sum = 0;
  for (int index = 0; index < m; ++index)
  {
    if (merge(edge[index].u, edge[index].v, leader))
    {
      count++;
      sum += edge[index].w;
      std::cout << "weight:" << edge[index].w << std::endl;
    }
    if (count == n - 1)
      break;
  }
  std::cout << sum << std::endl;
}
