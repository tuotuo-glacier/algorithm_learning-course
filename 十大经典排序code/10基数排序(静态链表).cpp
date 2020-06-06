#include <iostream>
using namespace std;
int data[10]={73, 22, 93, 43, 55, 14, 28, 65, 39, 81};  //�����������
typedef struct list  //��̬����ṹ������
{
    int data;
    int next;
}List;
List bucket[10];   //����ʮ��Ͱ
List d[10];        //�����������ݹ����list���͵�����
int maxbit(int data[],int n)   //�������������Ԫ�������λ��
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
void init(int data[],int n)  //��Ͱ�Ĺ��̣��Լ�����ʱ������ŵ�d��10��������
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
void RadioSort(int data[],int n)   //��������Ĺ���
{
    
    int p=maxbit(data,n);   //��������λ��
    int r=1;
    for(int i=0;i<p;i++)   //ִ��װͰ��Ͱ�Ĵ���
    {
        init(data,n);   //��λ��Ͱ�Ĺ���
        if(i!=0)   //��һ��װͰ��ʱ���С����ʼװ��֮�󶼴Ӵ�СװͰ
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
        for(int k=0;k<n;k++)   //��Ͱ�Ĺ��̣�����ŵ�data���鵱��
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
        r=r*10;  //Ϊ�˺����ʮλ���Լ���λ��ǰλ���ϵ�����
    }
}
int main()
{
    cout<<"���ھ�̬����Ļ�������c++ʵ��"<<endl;
    
    //cout<<maxbit(data,10)<<endl;
    cout<<"����֮ǰ����ֵ��";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    
    RadioSort(data,10);

    cout<<"����֮ǰ����ֵ��";
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";


    return 0;
}
