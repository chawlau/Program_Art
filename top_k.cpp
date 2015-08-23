#include<iostream>
#include<cstdlib>

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

int my_rand(int low, int high)
{
  int size = high - low + 1;
  return low + rand()%size;
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

//随机抽取一个数对数组进行切分
int random_partion(int array[], int left, int right)
{
  int index = my_rand(left, right);
  swap(array[right], array[index]);
  //return partion_rear(array, left, right);
  return partion(array, left, right);
}

int random_select(int array[], int left, int right, int k)
{
  if(k < 1 || k > (right - left + 1))
  {
    return -1;
  }
  int pos = random_partion(array, left, right);
  int m = pos - left + 1;
  if (m == k)
  {
    return array[pos];
  }
  else if (m > k)
  {
    return random_select(array, left, pos - 1, k);
  }
  else 
  {
    return random_select(array, pos + 1, right, k - m);
  }
}
int main(int argc,char** argv)
{
  int array[8] = {6 , 7 , 2, 4 , 1 , 3, 9, 5};
  scan(array, 8);
  std::cout << random_select(array, 0, 7, 6) <<std::endl;
}


