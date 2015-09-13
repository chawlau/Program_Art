#include <iostream>
void swap (int & left, int & right)
{
  int temp = left;
  left = right;
  right = temp;
}

int partion(int edge[], int left, int right)
{
  int pos = left;
  for (int index = left + 1; index < right + 1; ++index)
  {
    if (edge[index] < edge[left])
    {
      swap(edge[++pos], edge[index]);
    }
  }
  swap(edge[left], edge[pos]);
  return pos;
}

void quick_sort(int edge[],int left, int right)
{
  if (left > right)
    return;
  int pos = partion(edge, left, right);
  quick_sort(edge, left, pos - 1);
  quick_sort(edge, pos + 1, right);
}

int main(int argc,char ** argv)
{
  int array[] = {2,4,6,9,11,1,0,5};  
  quick_sort(array, 0, 7);
  for (int index = 0; index != 8; ++ index )
  {
    std::cout << array[index] << " ";
  }
  std::cout << std::endl;
}
