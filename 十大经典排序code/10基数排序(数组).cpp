/*基数排序（Radix sort） :稳定
1、算法过程：根据待排序元素的类型申请桶空间，并从待排序集合中计算出元素的最大位数；
从右向左，根据元素当前位数的值，将所有元素移动到对应的桶中；
将所有桶中元素移动回原始集合中；
重复步骤 2, 3，直到遍历完所有位数。
2、基数排序的时间复杂度为 O(KN)，其中K为元素最大位数，也就是迭代比较的次数。
算法过程中不存在元素之间的跨位置交换，属于稳定排序方式。
算法过程中需要申请的空间大小为 N+R，
其中 R 表示待排序元素的基数，例如示例中的十进制整数排序，则 R = 10；
若待排序元素为字符串，则 R = 26 ，因为基数的容量空间总是有限的，
所以算法的时间复杂度为O(N) 。
*/ 
#include<iostream>
using namespace std;
#include <vector>
int data[10]={73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
int tmp[10];
int count[10];
int maxbit(int data[],int n)
{
    int d=1;
    for(int i=0;i<n;i++)
    {
        int c=1;
        int p=data[i];
        while(p/10)
        {
            p=p/10;
            c++;
        }
        if(c>d)
            d=c;
    }
    return d;
}

void RadixSort(int data[],int n)
{    
    int d=maxbit(data,n);
        int r=1;
    for(int i=0;i<d;i++)
    {
    
        for(int i=0;i<10;i++)//装桶之前要先清桶
            count[i]=0;
        for(int i=0;i<n;i++) //记录每个桶的记录数
        {
            int k=data[i]/r;
            int q=k%10;
            count[q]++;
        }
        for(int i=1;i<10;i++)//计算位置
        {
            count[i]+=count[i-1];
            //cout<<count[i]<<" ";
        }
        for(int j=n-1;j>=0;j--)
        {
            int p=data[j]/r;
            int s=p%10;
            tmp[count[s]-1]=data[j];
            count[s]--;
            //cout<<data[j]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            data[i]=tmp[i];
            //cout<<tmp[i]<<" ";
        }
    //    cout<<endl;
        r=r*10;

    }

}
int main()
{
    cout<<"基数排序c++实现"<<endl;
    //cout<<maxbit(data,10)<<endl;
    cout<<"排序之前的数值：";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    RadixSort(data,10);
    cout<<"排序之前的数值：";
        for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;


    return 0;
}
