// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
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
class Solution {
public:
    ListNode* removeElements_org(ListNode* head, int val) {
        static ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        
        while (p->next) {
            if (p->next->val == val) {
            		ListNode *tmp = p->next->next;
            		delete(p->next);
                p->next = tmp;
            }else{
                p = p->next;
            }
        }
        
        return dummy.next;
    }

    ListNode* removeElements_org_1(ListNode* head, int val) {
      static ListNode dummy(-1);
      dummy.next = head;
      ListNode *p = &dummy;
      
      while (p)
      {
				if (p->next == NULL)
					break;
    		
        if (p->next->val == val) {
        	ListNode *tmp = p->next->next;
      		delete(p->next);
          p->next = tmp;
        }
				else
        	p = p->next; // bug: just in else branch, not in all branch
      }
      
      return dummy.next;
    }

//The more you understand the darkness of night, the better we know the light of day
//good taste above
// 2017/10/14
  ListNode* removeElements(ListNode* head, int val)
  {

		if (head == NULL)
			return NULL;

		ListNode* new_head = NULL;
		ListNode* node = head;
  	while (node)
  	{
			if (node->val == val)
			{
				ListNode* tmp = node->next;
				delete node;
				node = tmp;
				continue;
			}

			if (new_head == NULL)
				new_head = node;

			if (node->next == NULL)
				break;
  		
			if (node->next->val == val)
			{
				ListNode* tmp = node->next->next;
				delete(node->next);
				node->next = tmp;
			}
			else	
				node = node->next; // bug: just in else branch, not in all branch
  	}

		return new_head;
  }
};

// the test
//https://leetcode.com/problems/remove-linked-list-elements/description/
/*
[1,2,6,3,4,5,6]
6
[6,2,6,3,4,5,6]
6
[6,6,6,3,4,5,6]
6
[3,4,6,6,6,5,6]
6
[]
6
[6]
6

the expected answer:
[1,2,3,4,5]
[2,3,4,5]
[3,4,5]
[3,4,5]
[]
[]

*/
