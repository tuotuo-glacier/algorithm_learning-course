/*希尔排序（Shell Sort）是直接插入排序的改进，它的插入增量可以变化，
增量为2的shell排序的时间代价可以达到O(n的3/2次方)，
有的增量可以达到O(n的7/6次方)，很接近O(n)。*/ 
//将距离某个增量的子序列分割后，分别进行直接插入排序排序。
#include <iostream>
using namespace std;

void ShowArr(int arr[], int length)
{
	/*devcpp不支持c++特性nullptr 
    if (arr == nullptr || length <= 0)
        return;
    */ 
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void ShellSort(int arr[], int length)
{
    if (arr == NULL || length <= 0)
        return;
    int increment = length;
    while (increment > 1)
    {
        increment = increment / 3 + 1;
        for (int i = increment; i < length; i++)
        {
            int temp = arr[i];
            if (arr[i] < arr[i - increment])
            {
                int j;
                for (j = i - increment; j >= 0 && arr[j] > temp; j = j - increment)
                    arr[j + increment] = arr[j];
                arr[j + increment] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = { 592,401,874,141,348,72,91,887,820,283 };
    int length = sizeof(arr) / sizeof(int);
    ShowArr(arr, length);
    ShellSort(arr, length);
    ShowArr(arr, length);

    system("pause");
    return 0;
}
