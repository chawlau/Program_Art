#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXLEN 124
#define K 30

void swap(int & left, int & right)
{
  int temp = left;
  left = right;
  right = temp;
}
//非递归调整堆
void MinHeap_(int array[], int i, int length)
{
  int child,temp;
  for (temp = array[i]; 2 * i + 1 < length; i = child)
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
//递归调整堆
void MinHeap(int heap[], int i, int len)
{
  int minIndex = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2 ;
  if (left < len && heap[left] < heap[i])
    minIndex = left;
  if (right < len && heap[right] < heap[minIndex])
    minIndex = right;
  if (minIndex != i)
  {
    swap(heap[i], heap[minIndex]);
    MinHeap(heap, minIndex, len);
  }
}
//取得最小值
int GetMin(int array[], int k, int length)
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
      break;
    array[child] = temp;
  }
  return min;
}

void Kmin(int array[], int length, int k)
{
  //建堆
  for (int i = length/2 - 1; i >=0; --i)
    //MinHeap(array, i, length);
    MinHeap_(array, i, length);
  int j = length;
  //获取最小的值
  for (int i = k; i > 0; --i, --j)
  {
    int min = GetMin(array, i, j);
    std::cout << min << std::endl;
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
