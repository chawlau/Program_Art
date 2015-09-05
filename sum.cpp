#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
struct Pair
{
  int left_;
  int right_;
  int left_index_;
  int right_index_;
  Pair(int left, int left_index, int right, int right_index)
    : left_(left), left_index_(left_index), right_(right), right_index_(right_index)
  {
  }
  Pair(int left,int right)
    : left_(left), right_(right)
  {
  }
};

Pair find_factor(int array[], int sum, int len)
{
  int * start = array;
  int * end = array + len - 1;
  while (start < end)
  {
    if (*start + *end == sum)
    {
      return Pair(*start, *end);
    }
    else if(*start + *end < sum)
    {
      start++;
    }
    else
    {
      end--;
    }
  }
  return Pair(-1, -1);
}
int main(int argc, char** argv)
{
  int array[] = {1, 2, 3 , 6 , 7 , 11};
  Pair result = find_factor(array, atoi(argv[1]), sizeof(array)/sizeof(int));
  std::cout << result.left_ << "+" <<result.right_ << std::endl;
}
