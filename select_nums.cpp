#include <iostream>
using namespace std;

int select_nums(int data[], int right[], int len)
{
  right[len - 1] = data[len - 1];
  for (int index = len - 2; index >= 0; --index)
  {
    if (data[index] < data[index + 1])
      right[index] = data[index];
    else
      right[index] = data[index + 1];
  }
  int max = 0;
  for (int index = 0; index != len - 1; ++index)
  {
    if (data[index] > max)
    {
      max = data[index];
    }
    if (max == right[index])
      std::cout << right[index] << " ";
  }
  std::cout << std::endl;

}

int main()
{
  int data[]={2,3,5,12,6,9,10,15,19};
  int *right=new int[9];
  select_nums(data, right, 9);
  delete [] right;
}
