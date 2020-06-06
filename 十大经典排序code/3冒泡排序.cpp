/*
冒泡排序（Bubble Sort）：稳定、简单 
1、 算法描述
比较相邻的元素。如果第一个比第二个大，就交换它们两个；
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
针对所有的元素重复以上的步骤，除了最后一个；
重复步骤1~3，直到排序完成。
*/ 
/*
最坏情况下，当序列为逆序时，需要n-1次迭代才能结束排序过程， 每一次遍历都比较并交换待排序集合中所有元素位置，
即第 i次迭代，遍历的元素个数为n-i ，所以最坏情况下，算法的交换复杂度和比较复杂度都为O(n^2);
最好情况下，当序列为已排序时，第一次迭代即可结束排序过程，第一次遍历元素个数为n次，交换次数为 0，所以最好情况下，
算法的比较复杂度为O(n^2)，交换复杂度为 0。
链接：https://www.jianshu.com/p/4a06dcd45229
4、空间复杂度O(1) 
*/
#include <iostream>
using namespace std;
/*由小到大排序,n是数组长度*/
int bubble_sort(int arr[],int n){
	if(n<0)
		return 1;
	for(int i =0;i<n;i++){
		for(int j = 0;j < n-i-1;j++){
			if(arr[j+1]<arr[j]){
				swap(arr[j+1],arr[j]);
			}
		}
	}
	return 0;
} 
int main(){
	int array[10] = {5,8,9,4,1,0,3,9,4,1};
	bubble_sort(array,10);
	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
}
