/*快速排序（qucik sort）是一种非稳定排序算法，形式上类似于归并排序，操作上刚好相反，
一个是对集合先拆分后操作，一个是对集合先操作后拆分。对于N个元素的初始集合，
因为在每个子集合的拆分过程中，都需要对集合进行遍历比较，所以若对 N个元素的集合进行拆分，
则比较次数级别为O(K)，平均交换次数为K/2，即交换次数级别为O(K)。因为拆分集合的过程存在普通二叉树和斜树的情况，
所以树高为 log2N~N，每一层的平均比较和交换复杂度为 O(N)，所以累加可得快速排序的比较和交换复杂度为Nlog2N~N^2 。
排序过程属于原地排序，不需要额外的存储空间，所以空间复杂度为 O(log2N)~O(N)。
*/ 
void quickSort(int arr[],int b[],int left, int right)
{
	if(left >= right)
		return;
	int i, j, base;
	i = left, j = right;
	base = arr[left];  
	//取最左边的数为基准数，则右边哨兵先行。取右边为基准数，则左边哨兵先行。 
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			swap(arr[i],arr[j]);
			swap(b[i],b[j]);
		}
	}
	//基准数归位
	swap(arr[i],arr[left]);
	swap(b[i],b[left]);
	quickSort(arr,b,left, i - 1);//递归左边
	quickSort(arr,b,i + 1, right);//递归右边
}
