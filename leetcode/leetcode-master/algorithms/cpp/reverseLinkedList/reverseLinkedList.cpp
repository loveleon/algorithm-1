// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 *               
 **********************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#if 0
class Solution {
public:
    ListNode* reverseList_iteratively(ListNode* head) {
        ListNode *h=NULL, *p=NULL;
        while (head){
            p = head->next;
            head->next = h;
            h = head;
            head = p;
        }
        return h;
    }
    ListNode* reverseList_recursively(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *h = reverseList_recursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverseList_iteratively(head);
        return reverseList_recursively(head);
    }
};

#else

class Solution {
public:
  ListNode* reverseList(ListNode* head)
  {
		if (head == NULL)
			return NULL;

		ListNode* cur1 = NULL;
		ListNode* cur2 = head;
		while (cur2)
		{
			ListNode* tmp = cur2->next;
			cur2->next = cur1;
			cur1 = cur2;
			cur2 = tmp;
		}

		return cur1;
  }
};

#endif
