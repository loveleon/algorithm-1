// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : Hao Chen
// Date   : 2015-07-17

/********************************************************************************** 
 * 
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode* findMiddle(ListNode* head) {
        ListNode *p1=head, *p2=head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    
    ListNode* reverseLink(ListNode* head) {
        ListNode* p=NULL;
        
        while (head) {
            ListNode* q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* pMid = findMiddle(head);
        ListNode* pRev = reverseLink(pMid); 
        for(;head!=pMid; head=head->next, pRev=pRev->next) {
            if (head->val != pRev->val) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:

  ListNode* getmid(ListNode* head)
  {
    if (head == NULL || head->next == NULL)
      return NULL;
    
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    while (cur2 && cur2->next)
    {
      cur1 = cur1->next;
      cur2 = cur2->next->next;
    }

    return cur1;
  }

  ListNode* invertlist(ListNode* head)
  {
    ListNode* tmp  = NULL;
    ListNode* cur1 = NULL;
    ListNode* cur2 = head;
    while (cur2)
    {
      tmp = cur2->next;
      cur2->next = cur1;
      cur1 = cur2;
      cur2 = tmp;
    }

    return cur1;
  }

  bool isPalindrome(ListNode* head)
  {
    if (head == NULL || head->next == NULL)
      return true;
  
    ListNode* mid  = getmid(head);
    ListNode* tail = invertlist(mid);

    ListNode* cur1 = head;
    ListNode* cur2 = tail;
    while (cur1 != mid)
    {
      if (cur1->val != cur2->val)
        return false;
      
      cur1 = cur1->next;
      cur2 = cur2->next;
    }

    return true;
  }
};