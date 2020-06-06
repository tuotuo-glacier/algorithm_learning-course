// Merge sort for single list as ascending order
// single list node define
/*��ʵ�ϣ��鲢������ʺ϶�����������Ϊ�ںϲ���������ʱ������Ҫ����ĸ����ռ�洢��
����Ҳ����Ҫ�����ݿ�����ֱ���ƶ�ָ�뼴�ɡ�Ψһ�Ĳ����ǣ���Ҫÿ��Ѱ�ҵ�������м�ڵ㣬
Ȼ���Դ˽�������ָ�������֡�Ѱ���м�ڵ㣬���Զ�������ָ��fast��Mid��fastÿ���ƶ�������
midÿ���ƶ�һ������fast������β��ʱ��mid��ʱ���������м䣨���ÿ�����ż�����*/ 
/*��ʱ��������������������������mainû��ʵ�֣�����������copy��*/
#include <iostream>
using namespace std;
typedef struct __ListNode
{
	int val;
	struct __ListNode *next;
}ListNode;
// merge single list without head node (ascending order)
ListNode *merge_core(ListNode *i, ListNode *j)
{
	ListNode H, *p;
	for (p=&H; i && j; p=p->next){
		if (i->val < j->val){
			p->next = i;
			i = i->next;
		}
		else{
			p->next = j;
			j = j->next;
		}
	}
	p->next = (i ? i:j);
	return H.next;
}
// Merge sort for single list without head node
ListNode *merge_sort(ListNode *head)
{
	if (head==NULL || head->next==NULL) return head;
	ListNode *fast, *mid, H;
	// find mid node between head and end
	for (H.next=head, fast=mid=&H; fast && fast->next;){
		mid = mid->next;
		fast = fast->next->next;
	}
	fast = mid->next;
	mid->next = NULL;	// cut down mid part from head list
	mid = fast;

	head = merge_sort(head);
	mid = merge_sort(mid);
	return merge_core(head,mid);
}
int main(){
	int array[10] = {5,8,9,4,1,0,3,9,4,1};
	merge_sort(array);
	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
}

