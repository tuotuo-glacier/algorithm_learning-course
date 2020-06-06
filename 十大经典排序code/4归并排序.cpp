/*
�鲢����Merge sort�� 
�㷨�������ȶ�.
��������У��������Ԫ��ֵ��ȣ��򲻽���Ԫ��λ�á� 
������ֻ��һ��Ԫ�أ���ü���Ϊ����ģ����Խ�ԭʼ���ϲ��Ϊ���ֻ�е���Ԫ�ص��Ӽ��Ϻ�
��ÿ�κϲ�ѡ����������϶������򼯺ϡ�Ȼ�󽫺ϲ�������򼯺��ٽ��кϲ�������ִ�У�
ֱ���ϲ���ļ��ϰ�������Ԫ�أ������������
�㷨��ʱ�临�Ӷ�Ϊ��O(Nlog2N)���㷨ִ�й����У���Ҫ�����������пռ���������ʱԪ�أ�
�����㷨�Ŀռ临�Ӷ�Ϊ O(N)��
*/
#include <iostream>
using namespace std;
/*��С��������*/
void Merge_Sort_recursive(int arr[],int low,int high){
	void merge(int arr[],int low,int mid,int high);
	int mid = (low+high)/2;
	if(low<high){
		Merge_Sort_recursive(arr,low,mid);
		Merge_Sort_recursive(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
} 
void merge(int arr[],int low,int mid,int high){
	int temp[high-low+1] = {0};
	int i = low;
	int j = mid + 1;
	int k = 0;
	//�ѽ�С�������ƶ����µ����� 
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	//�����ʣ��Ԫ����������
	while(i <= mid){
		temp[k++] = arr[i++];
	} 
		//�����ʣ��Ԫ����������
	while(j <= high){
		temp[k++] = arr[j++];
	}
	//����ԭ��������
	for(int x = 0;x<=high-low;x++){
		arr[x+low] = temp[x];
	} 
}
int main(){
	int array[10] = {5,8,9,4,1,0,3,9,4,1};
	Merge_Sort_recursive(array,0,9);
	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
}
