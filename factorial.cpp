#include<iostream>
#include<cstdlib>
#include<cstdio>

int NumOfRear_1(int data){
  int num = 0;
  for (int index = 1; index <= data; index++){
    int temp = index;
    while(temp % 5 == 0){
      num ++ ;
      temp /= 5;
    }
  }
  return num;
}
//阶乘末尾几个零
int NumOfRear_2(int data){
  int num = 0;
  while(data){
    num += data / 5;//注意多检查
    data /= 5;
  }
  return num;
}
//阶乘最低位的1在第几位
int LowestOne(int data){
  int num = 0;
  while(data){
    data >>= 1;
    num += data;
  }
  return num;
}
int main(int argc, char ** argv){
  printf("num of factorial is %d\n", NumOfRear_1(10));
  printf("num of factorial is %d\n", NumOfRear_2(10));
  printf("lowets of factorial binary bite is %d\n", LowestOne(10) + 1);
}
