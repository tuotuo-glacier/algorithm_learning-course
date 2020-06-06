/*
归并排序（Merge sort） 
算法分析：稳定.
排序过程中，如果两个元素值相等，则不交换元素位置。 
若集合只有一个元素，则该集合为有序的，所以将原始集合拆分为多个只有单个元素的子集合后，
则每次合并选择的两个集合都是有序集合。然后将合并后的有序集合再进行合并，回溯执行，
直到合并后的集合包含所有元素，即完成了排序。
算法的时间复杂度为：O(Nlog2N)。算法执行过程中，需要申请额外的序列空间来保存临时元素，
所以算法的空间复杂度为 O(N)。
*/
#include <iostream>
using namespace std;
/*由小到大排序*/
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
	//把较小的数先移动到新的数组 
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	//把左边剩余元素移入数组
	while(i <= mid){
		temp[k++] = arr[i++];
	} 
		//把左边剩余元素移入数组
	while(j <= high){
		temp[k++] = arr[j++];
	}
	//覆盖原来的数组
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
