#include<iostream>
#include<cstdlib>
#include<cstdio>
#define N 10
/*不太完善的代码
int FindHalfMore(int data[]){
  int result = data[0];
  int count = 0;
  for(int index = 0; index < N; ++index){
    if (result != data[index]){
      count--;
      if (count == 0)
        result = data[index];
    } else if (result == data[index]){
      count++;
    }
  }
  return result;
}
*/
//正解
int FindHalfMore(int data[]){
  int result, count = 0;
  for (int index = 0; index < N; ++index){
    if (count == 0){
      result = data[index];
      count = 1;
    }else{
      if (result == data[index])
        count++;
      else
        count--;
    }
  }
  return result;
}
int main(int argc, char ** argv){
  int data[] = {3,3,3,4,5,3,3,15,3,5};
  printf(" more than half num is %d\n", FindHalfMore(data));
}
