#include <fstream>
#include <sstream>
#include <iostream>
template <typename T>
void load_data(T edge[][6])
{
  std::ifstream fin("data.txt");
  std::string number;
  while (getline(fin, number))
  {
    std::istringstream ss(number);
    int u,v,w;
    ss >> u >> v >> w;
    edge[u][v] = w;
    edge[v][u] = w;
  }
  for (int index = 0; index < 6; ++index)
  {
    for (int index_ = 0; index_ < 6; ++index_)
    {
      std::cout << edge[index][index_] << "  ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
template <typename T>
void init_edge(T edge[][6])
{
  for (int index = 0; index < 6; ++index)
  {
    for (int index_ = 0; index_ < 6; ++index_)
    {
      if (index == index_)
      {
        edge[index][index_] = 0;
      }
      else
      {
        edge[index][index_] = 100;
      }
    }
  }
  load_data(edge);
}

int main(int argc,char ** argv)
{
  int n = 6;
  int edge[6][6];
  init_edge(edge);
  int book[9]={0};
  int count = 0;
  count ++;
  book[0] = 1;
  int dis[6];
  for (int index = 0; index < 6; ++index)
    dis[index] = edge[0][index];
  int min = 0, min_index = 0;
  int sum = 0;
  while (count < n)
  {
    min = 100;
    for (int index = 0; index < n; ++index)
    {
      if(book[index] == 0 && dis[index] < min)
      {
        min = dis[index] ;
        min_index = index;
      }
    }
    book[min_index] = 1;
    count ++ ;
    sum += dis[min_index];
    for (int index = 0; index < n; index ++)
    {
      if (book[index] == 0 && dis[index] > edge[min_index][index])
        dis[index] = edge[min_index][index];
    }
  }
  std::cout << "sum = " << sum  << std::endl;
}
