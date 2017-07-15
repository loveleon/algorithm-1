// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Hao Chen
// Date   : 2014-06-21

/********************************************************************************** 
* 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
* 
*               
**********************************************************************************/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
ListNode *deleteDuplicates(ListNode *head) {

    for(ListNode *p=head; p && p->next; ){
        if (p->val == p->next->val){
            p->next = p->next->next;
            continue;
        }
        p=p->next;
    }
    return head;
}

#else
ListNode* deleteDuplicates(struct ListNode* head)
{
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	ListNode* cur = NULL;
	ListNode* next = NULL;
	ListNode* tmp  = NULL;
	
	if (!head)
		return NULL;

	cur = head;
	while (cur)
	{
		next = cur->next;

		if (!next)
			break; 

		while (next && cur->val == next->val)
		{
			tmp  = next;
			next = next->next;
			delete tmp;
		}

		cur->next = next;
		cur = next;
	}

	return head;
}

#endif

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main()
{
    int a[]={1,1,2,3,3};
    int b[]={1,1,1};

    printList(deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));
    printList(deleteDuplicates(createList(b, sizeof(b)/sizeof(int))));
    return 0;
}

