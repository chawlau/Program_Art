#include <iostream>
using namespace std;

//最长递增子序列的O（nlogn）方法
//lis[i]表示最长递增子序列的长度的i+1的最小的最后一个元素

int findlis(int *A,int n,int *lefttoright)     //从左向右最长递增子序列  
{
    if(A==NULL||n<0)
        return -1;
    int *lis=new int[n];
    lefttoright[0]=1;                    //lefttoright[i]保存从左到右，以i为终点的最长递增子序列长度，注意已经是正常的长度了，不是小一了
    int max=0;                           //max是lis[]的最大下标如lis[]={1,2,4}时,max=2;
    lis[0]=A[0];
    for(int i=1;i<n;i++)
    {
        int left=0;
        int right=max;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[i]>lis[mid])
                left=mid+1;
            else
                right=mid-1;
        }
        lis[left]=A[i];
        lefttoright[i]=left+1;    //lefttoright[i]等于left加一，同返回时是max+1同样道理
        if(left>max)          //如果left>max，则让max=left
            max++;
    }
    for (int index = 0; index != n; index++)
    {
      std::cout << lis[index] << " ";
    }
    std::cout << std::endl;
    delete [] lis;
    return max+1;             //注意，必须返回max+1，才是最终结果max是最长递增子序列长度减一
}

int findrighttoleftincrease(int *A,int n,int * righttoleft)  //从右向左最长递增子序列，也可以说成是从左向右最长递减子序列
{
    if(A==NULL||n<0)
        return -1;
    int *lis=new int[n];
    lis[0]=A[n-1];           //lis[0]=为A【n-1]
    righttoleft[n-1]=1;      //注意是lefttoright[n-1]=1
    int max=0;
    int left,right;
    for(int i=n-2;i>=0;i--)
    {
        left=0;
        right=max;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[i]>lis[mid])
                left=mid+1;
            else
                right=mid-1;
        }
        lis[left]=A[i];
        righttoleft[i]=left+1;
        if(left>max)                  //其实这时，max++后，max==left
            max++;
    }
    for (int index = 0; index != n; index++)
    {
      std::cout << lis[index] << " ";
    }
    std::cout << std::endl;
    delete [] lis;
    return max++;
}


int main()
{
    //网易的去掉最少元素使得从左向右递增然后递减，即为从左向右递增然后递减的最大值
    //Big=max（lefttoright[i]+righttoleft[i]-1}
    //所求即为n-Big。
    int A[]={2,3,5,1,6,9,10,15,7};
    int *lefttoright=new int[9];
    int *righttoleft=new int[9];
    int maxleft=findlis(A,9,lefttoright);
    if(maxleft==-1)
        cout<<"wrong"<<endl;
    else
        cout<<"max num lefttoright= "<<maxleft<<endl;
    int maxright=findrighttoleftincrease(A,9,righttoleft);
    if(maxright==-1)
        cout<<"wrong"<<endl;
    else
        cout<<"max num righttoleft= "<<maxright<<endl;
    int max=0;
    for(int i=0;i<9;i++)
    {
        if(lefttoright[i]+righttoleft[i]-1>max)
            max=lefttoright[i]+righttoleft[i]-1;
    }
    cout<<"去除"<<9-max<<endl;
    delete [] lefttoright;
    delete [] righttoleft;
}
