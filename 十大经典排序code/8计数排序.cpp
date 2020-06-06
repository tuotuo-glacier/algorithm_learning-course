/*
��������counting sort��
1���㷨���������ݴ����򼯺������Ԫ�غ���СԪ�صĲ�ֵ��Χ���������ռ䣻
���������򼯺ϣ���ÿһ��Ԫ�س��ֵĴ�����¼��Ԫ��ֵ��Ӧ�Ķ���ռ��ڣ�
�Զ���ռ������ݽ��м��㣬�ó�ÿһ��Ԫ�ص���ȷλ�ã�
�������򼯺�ÿһ��Ԫ���ƶ�������ó�����ȷλ���ϡ�
2�����������ʱ�临�Ӷ�ΪO(N+K)��
��Ϊ�㷨��������Ҫ����һ������ռ��һ��������򼯺ϴ�С��ͬ��������ռ䣬
���Կռ临�Ӷ�ΪO(N+K)��
3�������������������ֻ������Ԫ��ֵ��Ϊ���е������
�������д��������СԪ��ֵ�����Զ�������������������ϴ����ܽϲ
ͨ������ռ�����÷�ʽ��֪������ռ�洢Ԫ����Ϣ��ͨ������Ԫ������СԪ��ֵ�Ĳ�ֵ��Ϊ�±�����ɵģ�
�������򼯺��д���Ԫ��ֵΪ��������ʽ��������ʽ������Ҫ��Ԫ��ֵ��Ԫ�ز�ֵ���任��
�Ա�֤���в�ֵ��Ϊһ���Ǹ�������ʽ��
*/ 
#include <iostream>
using namespace std;
class Solution
{
public:
    int* coutSort(int* data, int length)
    {
    	/*devcpp��֧��c++����nullptr
        if (data == nullptr || length <= 0)
            return nullptr;
		*/
        //ȷ���������ֵ
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
        // ȷ��ͳ�����鳤�Ȳ����г�ʼ��
        int* coutData = new int[d + 1];
        for (int i = 0; i <= d; ++i)
            coutData[i] = 0;
        // �������飬ͳ��ÿ�������ֵĴ���
        for (int i = 0; i < length; ++i)
                ++coutData[data[i] - min];
        // ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮��
        for (int i = 1; i <= d; ++i)
            coutData[i] += coutData[i - 1];
    	// �������ԭʼ���У���ͳ�������ҵ���ȷ��λ�ã�������������
        int* sortedArray = new int[length];
        for (int i = length - 1; i >= 0; i--)
        {
            sortedArray[coutData[data[i] - min] - 1] = data[i];        
			// �ҵ�data[i]��Ӧ��coutData��ֵ��ֵΪ���٣���ʾԭ��������٣�����Ϊ��1��ʼ�������ټ�1��
            coutData[data[i] - min]--;        
			// Ȼ����Ӧ��coutData��ֵ��1����ʾ�´���������ֵʱ��ԭ���������Ƕ��١�
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

