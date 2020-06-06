/*ϣ������Shell Sort����ֱ�Ӳ�������ĸĽ������Ĳ����������Ա仯��
����Ϊ2��shell�����ʱ����ۿ��ԴﵽO(n��3/2�η�)��
�е��������ԴﵽO(n��7/6�η�)���ܽӽ�O(n)��*/ 
//������ĳ�������������зָ�󣬷ֱ����ֱ�Ӳ�����������
#include <iostream>
using namespace std;

void ShowArr(int arr[], int length)
{
	/*devcpp��֧��c++����nullptr 
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
