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
      std::cout << edge[index][index_] << "  ";
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
void broad_explore(int book[][N], Note que[], int a[][N], int next[][2], int color)
{
  int head, tail;
  head = 0, tail = 0;
  que[tail].x = 5;
  que[tail].y = 7;
  que[tail].color = -1;
  tail ++;
  book[5][7] = 1;
  int k = 0, tx, ty, sum = 1;
  while (head < tail)
  {
    for (k = 0; k < 4; ++k)
    {
      tx = que[head].x + next[k][0];
      ty = que[head].y + next[k][1];
      if (tx < 1 || tx > M - 1 || ty < 1 || ty > N - 1)
        continue;
      if (a[tx][ty] > 0 && book[tx][ty] == 0)
      {
        sum ++;
        book[tx][ty] = 1;
        que[tail].x = tx;
        que[tail].y = ty;
        que[tail].color = color;
        tail ++;
      }
    }
    head++;
  }
  for (int index = 0; index < tail; ++ index)
  {
    a[que[index].x][que[index].y] = -1;
  }
  print(a);
  printf("sum island -->%d ", sum);
}
int main(int argc, char ** argv)
{
  Note que[2501];
  int a[M][N] = {0}, book[M][N] = {0};
  int next[4][2] = { {0,1}, { 1, 0} , { 0 , -1} ,{ -1, 0} };
  load_data(a);
  broad_explore(book, que, a, next, -1);
}

