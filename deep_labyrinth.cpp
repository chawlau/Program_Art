#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
struct Note
{
  int x;
  int y;
  int f;
  int s;
};
template <typename T>
void load_data(T edge[][4])
{
  std::ifstream fin("data1.txt");
  std::string number;
  int _i = 0, _j = 0;
  while (getline(fin, number))
  {
    _j = 0;
    std::istringstream ss(number);
    int data;
    while (ss >> data)
    {
      edge[_i][_j++] = data;
    }
    ++ _i;
  }
  for (int index = 0; index < 5; ++index)
  {
    for (int index_ = 0; index_ < 4; ++index_)
    {
      std::cout << edge[index][index_] << "  ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
int a[5][4] = {0}, book[50][50] = {0};
int next[4][2] = { {0,1}, { 1, 0} , { 0 , -1} ,{ -1, 0} };
int p = 3, q = 2;
int min = 100;
void dfs(int x, int y, int step)
{
  int tx,ty,k;
  if (x == p && y == q)
  {
    if (step < min)
      min = step;
    return;
  }
  for (k =0; k < 4; ++k)
  {
    tx = x + next[k][0];
    ty = y + next[k][1];
    if (tx < 0 || tx > 4 || ty < 0 || ty > 4)
      continue;
    if (a[tx][ty] == 0 && book[tx][ty] == 0)
    {
      book[tx][ty] = 1;
      dfs(tx, ty, step + 1);
      book[tx][ty] = 0;
    }
  }
}
int main(int argc, char ** argv)
{
  load_data(a);
  book[0][0] = 1;
  dfs(0, 0 ,0);
  std::cout << min << std::endl;
}

