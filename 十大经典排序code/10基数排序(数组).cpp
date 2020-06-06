/*��������Radix sort�� :�ȶ�
1���㷨���̣����ݴ�����Ԫ�ص���������Ͱ�ռ䣬���Ӵ����򼯺��м����Ԫ�ص����λ����
�������󣬸���Ԫ�ص�ǰλ����ֵ��������Ԫ���ƶ�����Ӧ��Ͱ�У�
������Ͱ��Ԫ���ƶ���ԭʼ�����У�
�ظ����� 2, 3��ֱ������������λ����
2�����������ʱ�临�Ӷ�Ϊ O(KN)������KΪԪ�����λ����Ҳ���ǵ����ȽϵĴ�����
�㷨�����в�����Ԫ��֮��Ŀ�λ�ý����������ȶ�����ʽ��
�㷨��������Ҫ����Ŀռ��СΪ N+R��
���� R ��ʾ������Ԫ�صĻ���������ʾ���е�ʮ�������������� R = 10��
��������Ԫ��Ϊ�ַ������� R = 26 ����Ϊ�����������ռ��������޵ģ�
�����㷨��ʱ�临�Ӷ�ΪO(N) ��
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
    
        for(int i=0;i<10;i++)//װͰ֮ǰҪ����Ͱ
            count[i]=0;
        for(int i=0;i<n;i++) //��¼ÿ��Ͱ�ļ�¼��
        {
            int k=data[i]/r;
            int q=k%10;
            count[q]++;
        }
        for(int i=1;i<10;i++)//����λ��
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
    cout<<"��������c++ʵ��"<<endl;
    //cout<<maxbit(data,10)<<endl;
    cout<<"����֮ǰ����ֵ��";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    RadixSort(data,10);
    cout<<"����֮ǰ����ֵ��";
        for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;


    return 0;
}
