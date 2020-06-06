// Merge sort for single list as ascending order
// single list node define
/*事实上，归并排序更适合对链表排序，因为在合并两个链表时，不需要额外的辅助空间存储，
而且也不需要对数据拷贝，直接移动指针即可。唯一的不便是：需要每次寻找到链表的中间节点，
然后以此将该链表分割成两部分。寻找中间节点，可以定义两个指针fast和Mid，fast每次移动两步，
mid每次移动一步，当fast到链表尾部时，mid此时处于链表中间（不用考虑奇偶情况）*/ 
/*暂时不会链表！！！！！！！！所以main没有实现，其他是网上copy的*/
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

