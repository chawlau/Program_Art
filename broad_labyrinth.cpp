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
int main(int argc, char ** argv)
{
  Note que[2501];
  int a[5][4] = {0}, book[50][50] = {0};
  int next[4][2] = { {0,1}, { 1, 0} , { 0 , -1} ,{ -1, 0} };
  int head, tail;
  load_data(a);
  head = 0, tail = 0;
  que[tail].x = 0;
  que[tail].y = 0;
  que[tail].f = 0;
  que[tail].s = 0;
  tail ++;
  book[0][0] = 1;
  int k = 0, tx, ty, p = 3, q = 2, flag = 0;
  while (head < tail)
  {
    for (k = 0; k < 4; ++k)
    {
      tx = que[head].x + next[k][0];
      ty = que[head].y + next[k][1];
      std::cout << "tx:" << tx << " ty: " << ty << std::endl;
      if (tx < 0 || tx > 4 || ty < 0 || ty > 4)
        continue;
      if (a[tx][ty] == 0 && book[tx][ty] == 0)
      {
        book[tx][ty] = 1;
        que[tail].x = tx;
        que[tail].y = ty;
        que[tail].f = head;
        que[tail].s = que[head].s + 1;
        tail ++;
      }
      if (tx == p && ty == q)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      break;
    }
    head++;
  }
  std::cout << que[tail - 1].s << std::endl;
}

