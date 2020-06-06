/*
计数排序（counting sort）
1、算法分析：根据待排序集合中最大元素和最小元素的差值范围，申请额外空间；
遍历待排序集合，将每一个元素出现的次数记录到元素值对应的额外空间内；
对额外空间内数据进行计算，得出每一个元素的正确位置；
将待排序集合每一个元素移动到计算得出的正确位置上。
2、计数排序的时间复杂度为O(N+K)。
因为算法过程中需要申请一个额外空间和一个与待排序集合大小相同的已排序空间，
所以空间复杂度为O(N+K)。
3、适用情况：计数排序只适用于元素值较为集中的情况，
若集合中存在最大最小元素值相差甚远的情况，则计数排序开销较大、性能较差。
通过额外空间的作用方式可知，额外空间存储元素信息是通过计算元素与最小元素值的差值作为下标来完成的，
若待排序集合中存在元素值为浮点数形式或其他形式，则需要对元素值或元素差值做变换，
以保证所有差值都为一个非负整数形式。
*/ 
#include <iostream>
using namespace std;
class Solution
{
public:
    int* coutSort(int* data, int length)
    {
    	/*devcpp不支持c++特性nullptr
        if (data == nullptr || length <= 0)
            return nullptr;
		*/
        //确定数列最大值
        int max = data[0];
        int min = data[0];
        for (int i = 1; i < length; ++i)
        {
            if (data[i] > max)
                max = data[i];
            if (data[i] < min)
                min = data[i];
        }
        int d = max - min;
        // 确定统计数组长度并进行初始化
        int* coutData = new int[d + 1];
        for (int i = 0; i <= d; ++i)
            coutData[i] = 0;
        // 遍历数组，统计每个数出现的次数
        for (int i = 0; i < length; ++i)
                ++coutData[data[i] - min];
        // 统计数组做变形，后面的元素等于前面的元素之和
        for (int i = 1; i <= d; ++i)
            coutData[i] += coutData[i - 1];
    	// 倒序遍历原始数列，从统计数组找到正确的位置，输出到结果数组
        int* sortedArray = new int[length];
        for (int i = length - 1; i >= 0; i--)
        {
            sortedArray[coutData[data[i] - min] - 1] = data[i];        
			// 找到data[i]对应的coutData的值，值为多少，表示原来排序多少，（因为从1开始，所以再减1）
            coutData[data[i] - min]--;        
			// 然后将相应的coutData的值减1，表示下次再遇到此值时，原来的排序是多少。
        }
        return sortedArray;
    }
};
int main()
{
    int data[] = { 95, 98, 97, 90, 98, 93, 92, 91 };
    int length = sizeof(data) / sizeof(int);

    Solution M;
    int* array = M.coutSort(data, length);

    for (int i = 0; i < length; ++i)
        cout << array[i] << "  ";
    cout << endl;
}

