#include <iostream>
using namespace std;
int data[10]={73, 22, 93, 43, 55, 14, 28, 65, 39, 81};  //待排序的数组
typedef struct list  //静态链表结构体类型
{
    int data;
    int next;
}List;
List bucket[10];   //构造十个桶
List d[10];        //将待排序数据构造成list类型的数组
int maxbit(int data[],int n)   //计算待排序数组元数的最长的位数
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
void init(int data[],int n)  //清桶的过程，以及将临时的数组放到d【10】数组中
{
       int j=0; 
        for(j=0;j<n;j++)
        {
            bucket[j].next=-1;
            bucket[j].data=j;
        }
        for(j=0;j<n;j++)
        {
          d[j].data=data[j];
          d[j].next=-1;
        }
}
void RadioSort(int data[],int n)   //基数排序的过程
{
    
    int p=maxbit(data,n);   //先求出最长的位数
    int r=1;
    for(int i=0;i<p;i++)   //执行装桶倒桶的次数
    {
        init(data,n);   //复位清桶的过程
        if(i!=0)   //第一次装桶的时候从小到大开始装，之后都从大到小装桶
        {    
            for(int k=n-1;k>=0;k--)
            {
                int a=d[k].data/r;
                int b=a%10;
                d[k].next=bucket[b].next;
                bucket[b].next=k;
            }
        }
        else
        {
            for(int k=0;k<n;k++)
            {
                int a=d[k].data/r;
                int b=a%10;
                d[k].next=bucket[b].next;
                bucket[b].next=k;
            }
        }
        
        int c=0;
        for(int k=0;k<n;k++)   //倒桶的过程，将其放到data数组当中
        {    
            
            if(bucket[k].next!=-1)
            {
                int p=bucket[k].next;
                data[c++]=d[p].data;
                while(d[p].next!=-1){
                        data[c++]=d[d[p].next].data;
                        p=d[p].next;
                }
            }
        }
        r=r*10;  //为了后面对十位数以及高位求当前位置上的数字
    }
}
int main()
{
    cout<<"基于静态链表的基数排序c++实现"<<endl;
    
    //cout<<maxbit(data,10)<<endl;
    cout<<"排序之前的数值：";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    
    RadioSort(data,10);

    cout<<"排序之前的数值：";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";


    return 0;
}
