#include <stdio.h>
/*
ʱ�临�Ӷȣ�
��ã�O(n log2 n)
���O(n log2 n)
ƽ����O(n log2 n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/ 
/*��ϸ���ͣ�����������https://blog.csdn.net/lyl771857509/article/details/78853448*/ 
/*����������void swap(int array[],int x,int y)
��ʼ���󶥶Ѻ�����void BuildHeap(int array[],int size)
���ɴ󶥶Ѻ�����void Down(int array[],int i,int n)
��������void heapSort(int array[],int size)
������Դ��https://blog.csdn.net/weixin_42109012/article/details/91668543*/ 
void swap(int array[],int x,int y){
	int key;
	key=array[x];
	array[x]=array[y];
	array[y]=key;
}

//�Ӵ�С���� 
//void Down(int array[],int i,int n){
//	int child=2*i+1;
//	int key=array[i];
//	while (child<n){
//		if (array[child]>array[child+1] && child+1<n) {
//			child++;
//		}
//		if (key>array[child]){
//			swap(array, i, child);
//			i=child;
//		}
//		else{
//			break;
//		}
//		child=child*2+1;
//	}
//}

//��С��������
void Down(int array[],int i,int n){						//��������Ǵ󶥶� 
	int parent=i;										//���ڵ��±�
	int child=2*i+1;									//�ӽڵ��±�  
	while (child<n){
		if (array[child]<array[child+1] && child+1<n) {	//�ж��ӽڵ��Ǹ��󣬴���븸�ڵ�Ƚ� 
			child++;
		}
		
		if (array[parent]<array[child]){				//�жϸ��ڵ��Ƿ�С���ӽڵ� 
			swap(array, parent, child);					//�������ڵ���ӽڵ� 
			parent=child;								//�ӽڵ��±� ���� ���ڵ��±� 
		}

		child=child*2+1;								//���У��Ƚ�����ĸ��ڵ���ӽڵ� 
	}
}

void BuildHeap(int array[],int size)
{
   int i=0;												//�����ڶ��ſ�ʼ 
   for(i=size/2-1;i>=0;i--){							//�����󶥶ѣ�����������ϱȽ� 
      Down(array,i,size);								//�����еĲ����ϴ󶥶Ѷ��� 
  	}
}

void heapSort(int array[],int size){
    BuildHeap(array,size);								//��ʼ���� 
    printf("��ʼ�����飺");
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	
    for(int i=size-1;i>0;i--)
    {	
    	swap(array,0,i);								//��������͵� i ������ 
    	//��Ϊֻ��array[0]�ı䣬���������ϴ󶥶ѵĶ��壬���Կ��Դ����������½��� 
    	Down(array,0,i);								//���½����󶥶� 
    	
    	printf("��������飺");
		for(int i=0;i<size;i++){
			printf("%d ",array[i]);
		}
		printf("\n");
	}
}

int main(){
	int array[]={49,38,65,97,76,13,27,49,10};
	int size= sizeof(array) / sizeof(int);
	printf("���鳤�� = %d \n",size);
	printf("����ǰ���飺");
		for(int i=0;i<size;i++){
			printf("%d ",array[i]);
		}
	printf("\n");
	heapSort(array,size);
	
	return 0;
}

