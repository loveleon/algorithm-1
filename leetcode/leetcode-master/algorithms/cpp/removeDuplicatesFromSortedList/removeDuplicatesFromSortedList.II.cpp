// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
* 
*               
**********************************************************************************/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
/*
    ~ListNode()
    {
    	next = NULL;
    }
*/

};

#if 0
ListNode *deleteDuplicates(ListNode *head) {
    ListNode fake(-1);
    fake.next = head;
    head = &fake;

    ListNode *tail=head;

    bool dup = false;
    for(ListNode *p=head->next;  p && p->next; p=p->next){
        if (dup==false && p->val == p->next->val){
            dup = true;            
            continue;
        }
        if (dup==true && p->val != p->next->val){
            dup = false;
            tail->next = p->next;
            continue;
        }
        if (dup==false){
            tail = p;
        }
    }
    if (dup==true){
        tail->next = NULL;
    }
    return head->next;
}
#else
ListNode* deleteDuplicates(struct ListNode* head)
{
	ListNode* pre = NULL;
	ListNode* cur = NULL;
	ListNode* next = NULL;
	ListNode* tmp  = NULL;
	ListNode* new_head = NULL;
	bool head_flag = true;

	if (!head)
		return NULL;

	cur = head;
	while (cur)
	{
		next = cur->next;
		if (next && cur->val == next->val)
		{
			while (next && cur->val == next->val)
			{
				tmp  = next;
				next = next->next;
				delete tmp;
				tmp = NULL;
			}

			delete cur;
			cur = next;
			continue;
		}

		if (head_flag)
		{
			new_head = cur;
			pre = cur;
			head_flag = false;
		}
		else //
		{
			pre->next = cur;
			pre = cur;
		}
		cur = cur->next;
	}

	if (pre)
		pre->next = NULL;

	return new_head;
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
 
   int c[]={1,2,3};
 
   int d[]={1,1,2,2,3};

   printf("test1:\n");
   printList(deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));
   printf("test2:\n");
   printList(deleteDuplicates(createList(b, sizeof(b)/sizeof(int))));
   printf("test3:\n");
   printList(deleteDuplicates(createList(c, sizeof(c)/sizeof(int))));
   printf("test4:\n");
   printList(deleteDuplicates(createList(d, sizeof(d)/sizeof(int))));
 
   return 0;

}


