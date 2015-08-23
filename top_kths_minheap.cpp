#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 123456
#define K 100

void swap(int & left, int & right)
{
  int temp = left;
  left = right;
  right = temp;
}

void HeapAdjust(int array[], int i, int length)
{
  int child,temp;
  for (temp = array[i]; 2*i + 1 < length; i = child)
  {
    child = 2 * i + 1;
    if (child < length - 1 && array[child + 1] < array[child])
      child++;
    if (temp > array[child])
      array[i] = array[child];
    else
      break;
    array[child] = temp;
  }
}

int GetMin(int array[], int length, int k)
{
  int min = array[0];
  swap(array[0], array[length - 1]);
  int child,temp;
  int i = 0,j = k - 1;
  for (temp = array[i]; j > 0 && 2 * i + 1 < length; --j,i = child)
  {
    child = 2 * i + 1;
    if (child < length - 1 && array[child + 1] < array[child])
      child++;
    if (temp > array[child])
      array[i] = array[child];
    else
      brak;
    array[child] = temp;
  }
  return min;
}

void Kmin(int array[], int length, int k)
{
  for (int i = length/2 - 1; i >=0; --i)
    HeapAdjust(array, i, length);
  int j = length;
  for (i = k; i > 0; --i, --j)
  {
    int min = Getmin(array, j, i);
    std::cout << min;
  }
}

int main(int argc, char** argv)
{
  int array[MAXLEN];
  for (int i = MAXLEN; i > 0; --i)
    array[MAXLEN - i] = i;
  Kmin(array, MAXLEN, K);
  return 0;
}
