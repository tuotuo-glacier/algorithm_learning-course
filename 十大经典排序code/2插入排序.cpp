/*
插入排序（Insertion Sort ） 
是一种稳定排序算法，排序过程中，如果两个元素值相等，则不交换元素位置。
对于n个元素的序列：
最坏情况下，当序列为逆序时，每一次迭代过程中，都需要比较并交换新元素与其左边的所有元素位置，
即第i次迭代，新元素左边的元素个数为i+1，所以最坏情况下，算法的交换复杂度和比较复杂度都为O(N^2);
最好情况下，当序列为已排序时，每一次迭代过程中，只需要做一次比较即可，所以最好情况下，算法的比较复杂度为O(N)，交换复杂度为 0。
算法执行过程中，不需要申请额外的序列空间来保存临时元素，属于原地排序方式，所以算法的空间复杂度为O(1)
*/
#include <iostream>
using namespace std;
/*由小到大排序*/
int Insertion_sort(int arr[],int n){
	int temp,j;//待排序元素 
	if(n<0)
		return 1;
	/*默认第一个元素是已经排好的序列*/ 
	for(int i = 1;i<n;i++){
		/*已排好序列从后往前比较*/
		temp = arr[i]; 
		j = i-1;
		while(j>=0&&temp<arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;//原本写arr[j]是错的，要考虑上面j--后不满足条件才停止 
	} 
	return 0;
} 
int main(){
	int array[10] = {5,8,9,4,1,0,3,9,4,1};
	Insertion_sort(array,10);
	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
}
