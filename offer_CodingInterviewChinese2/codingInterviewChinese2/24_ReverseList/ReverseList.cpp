/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣

#include <cstdio>
#include "../Utilities/List.h"

ListNode* ReverseList_org(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while(pNode != nullptr)
    {
        ListNode* pNext = pNode->m_pNext;

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

// the org is clean and good taste, need to learn
ListNode* ReverseList(ListNode* phead)
{
  if (phead == NULL)
    return NULL;

  ListNode* first  = phead;
  ListNode* second = phead->m_pNext;
  ListNode* pnode = NULL;

  first->m_pNext = NULL;
  
  while (second != NULL)
  {
    pnode  = second->m_pNext;
    second->m_pNext = first;
    first  = second;
    second = pnode;
  }

  return first;
}

ListNode* ReverseList1(ListNode* phead)
{
    if (phead == NULL)
        return NULL;

    ListNode *p1 = phead;
    ListNode *p2 = phead->m_pNext;
    p1->m_pNext = NULL;
    while (p2 != NULL)
    {
        ListNode *t = p2->m_pNext;
        p2->m_pNext = p1;
        p1 = p2;
        p2 = t; 
    }
    
    return p1;
}
// ====================���Դ���====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������ֻ��һ�����
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

