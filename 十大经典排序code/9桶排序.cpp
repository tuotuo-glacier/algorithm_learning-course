/*算法：桶排序（Bucket sort） 
1、算法过程：
根据待排序集合中最大元素和最小元素的差值范围和映射规则，确定申请的桶个数；
遍历待排序集合，将每一个元素移动到对应的桶中；
对每一个桶中元素进行排序，并移动到已排序集合中。 
2、桶排序的时间复杂度为 O(N+N(log_2N-log_2M))，
其中 M 表示桶的个数。由于需要申请额外的空间来保存元素，
并申请额外的数组来存储每个桶，所以空间复杂度为 O(N+M)。
3、 适用情况：算法的稳定性取决于对桶中元素排序时选择的排序算法。
由桶排序的过程可知，当待排序集合中存在元素值相差较大时，对映射规则的选择是一个挑战，可
能导致元素集中分布在某一个桶中或者绝大多数桶是空桶的现象，
对算法的时间复杂度或空间复杂度有较大影响，所以同计数排序一样，
桶排序适用于元素值分布较为集中的序列。
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void bksort(float A[],int l,int h){
    int size = h-l+1;
    vector<float> b[size];//有size个数据，就分配size个桶
    for(int i=l;i<=h;i++){
        int bi = size*A[i];//元素A[i]的桶编号
        b[bi].push_back(A[i]);//将元素A[i]压入桶中
    }
    for(int i=0;i<size;i++)
        sort(b[i].begin(),b[i].end());//桶内排序
    int idx = l;//指向数组A的下标
    for(int i=0;i<size;i++){//遍历桶
        for(int j=0;j<b[i].size();j++){//遍历桶内元素
            A[idx++] = b[i][j];
        }
    }
}
 
int main(){
    float A[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    bksort(A,0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
}
