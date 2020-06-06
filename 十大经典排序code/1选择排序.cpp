/*
选择排序（Selection sort） ：不稳定 
1、初始状态：无序区为R[1..n]，有序区为空；
第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。
该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，
使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
n-1趟结束，数组有序化了。
*/
/*
2、最差时间复杂度O(N^2)
3、最好的情况时间复杂度为O(n)
4、空间复杂度O(1) 
5、算法的比较复杂度为 O(n^2)，交换复杂度为 O(n)
*/ 
/*
表现最稳定的排序算法之一，因为无论什么数据进去都是O(N^2)的时间复杂度，
与输入的顺序无关,所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。
*/ 
#include <iostream>
using namespace std;
/*由小到大排序*/
int selection_sort(int arr[],int n){
	int min_state;
	if(n<0)
		return 1;
	for(int i =0;i<n;i++){
		min_state = i;
		for(int j = i;j < n;j++){
			if(arr[j]<arr[min_state]){
				min_state = j;
			}
			if(min_state!=i) 
				swap(arr[min_state],arr[i]);
		}
	}
	return 0;
} 
int main(){
	int array[10] = {5,8,9,4,1,0,3,9,4,1};
	selection_sort(array,10);
	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
}
