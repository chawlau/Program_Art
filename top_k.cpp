#include<iostream>

void swap(int & left, int & right)
{

  int temp = left;
  left = right;
  right = temp;

}

void scan(int * array, int length)
{
  for(int index = 0; index != length; index++)
  {
    std::cout << array[index] << " ";
  }
  std::cout << std::endl;
}

//以第一个元素对数组进行一次划分
int partion(int* array, int left, int right)
{
  int pos = left;
  for(int index = left + 1; index != right + 1; index++)
  {
    if(array[index] < array[left])
    {
      swap(array[++pos], array[index]);
    }
  }
  swap(array[left], array[pos]);
  return array[pos];
}

//以最后一个元素对数组进行一次划分
int partion_rear(int * array, int left, int right)
{
  int pos = right;
  for(int index = right - 1; index >= left; index--)
  {
    if(array[index] > array[right])
    {
      swap(array[--pos], array[index]);
    }
  }
  swap(array[pos], array[right]);
  return pos;
}

int main(int argc,char** argv)
{
  int array[8] = {6 , 7 , 2, 4 , 1 , 3, 9, 5};
  scan(array, 8);
  partion(array, 0, sizeof(array)/sizeof(int)-1);
  //partion_rear(array, 0, 7) ;
  scan(array, 8);
}


