#include <iostream>
using namespace std;
int left_right(int data[], int len, int lefttoright[])
{
  if (data == NULL || len <0)
    return -1;
  int lis[len];
  lis[0] = data[0];
  lefttoright[0] = 1;
  int left = 0,max = 0, right = 0, mid = 0;
  for (int index = 1; index != len; ++index)
  {
     left = 0;
     right = max;
     while (left <= right)
     {
       mid = (left + right) / 2;
       if (data[index] > lis[mid])
         left = mid + 1;
       else
         right = mid - 1;
     }
     lis[left] = data[index];
     lefttoright[index] = left + 1;
     if (left > max)
       max = left;
  }
  return ++max;
}
int right_left(int data[], int len, int righttoleft[])
{
  if (data == NULL || len <0)
    return -1;
  int lis[len];
  lis[0] = data[len - 1];
  righttoleft[len - 1] = 1;
  int left = 0,max = 0, right = 0, mid = 0;
  for (int index = len - 2; index >= 0; --index)
  {
    left = 0;
    right = max;
    while (left <= right)
    {
      mid = (left + right) / 2;
      if (data[index] > lis[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }
    lis[left] = data[index];
    righttoleft[index] = left + 1;
    if (left > max)
      max = left;
  }
  return ++max;
}

int delete_num(int data[], int left[], int right[], int len)
{
  left_right(data, len, left);
  right_left(data, len, right);
  int max = 0;
  for (int index =0; index != len; ++index)
  {
    std::cout << data[index] << ":" 
      << left[index] << "--" <<":" << right[index] << std::endl;
    if (left[index] + right[index] - 1 > max)
      max = left[index] + right[index] - 1;
  }
  return len - max;
}

int main()
{
  int data[]={2,3,5,12,6,9,10,15,19};
  int *left=new int[9];
  in *right=new int[9];
  std::cout << "delete num " << delete_num(data, left, right, 9) << std::endl;
  delete [] left;
  delete [] right;
}
