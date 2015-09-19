#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#define M 10
#define N 10
struct Note
{
  int x;
  int y;
  int color;
};
template <typename T>
void print(T edge[M][N])
{
  for (int index = 0; index < M; ++index)
  {
    for (int index_ = 0; index_ < N; ++index_)
    {
      printf("%3d",edge[index][index_]);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
template <typename T>
void load_data(T  edge[M][N])
{
  std::ifstream fin("map.txt");
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
  print(edge);
}
Note que[2501];
int a[M][N] = {0}, book[M][N] = {0};
int next[4][2] = { {0,1}, { 1, 0} , { 0 , -1} ,{ -1, 0} };
int sum = 0, num = 0;
void deep_explore(int x, int y, int color)
{
  a[x][y] = color;
  int k = 0, tx, ty;
  for (k = 0; k < 4; ++k)
  {
    tx = x + next[k][0];
    ty = y + next[k][1];
    if (tx < 1 || tx > M - 1 || ty < 1 || ty > N - 1)
      continue;
    if (a[tx][ty] > 0 && book[tx][ty] == 0)
    {
      sum ++;
      book[tx][ty] = 1;
      deep_explore(tx, ty, color);
    }
  }
  return;
}
int main(int argc, char ** argv)
{
  load_data(a);
  for (int index = 0; index < M; ++index)
  {
    for (int index_ = 0; index_ < N; ++index_)
    {
      if (a[index][index_] > 0)
      {
        --num;
        book[index][index_] = 1;
        deep_explore(index, index_, num);
      }
    }
  }
  print(a);
}

