/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <cstdio>
#include <string>
#include "../Utilities/List.h"
using namespace std;

void DeleteDuplication_org(ListNode** pHead)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;
    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;

        if(!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while(pToBeDel != nullptr && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = nullptr;

                pToBeDel = pNext;
            }

            if(pPreNode == nullptr)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;
            pNode = pNext;
        }
    }
}

void DeleteDuplication(ListNode** pphead)
{
  if (pphead == NULL | *pphead == NULL)
    return;
  
  ListNode* pprenode = nullptr;
  ListNode* pnode = *pphead;

  while (pnode != NULL)
  {
    bool dup_flag = false;
    ListNode* pnext = pnode->m_pNext;

    if (pnext != NULL && pnext->m_nValue == pnode->m_nValue)
    {
      dup_flag = true;
    }

    if (dup_flag != true)
    {
      pprenode = pnode;
      pnode = pnode->m_pNext;
    }
    else //del the node with the same value
    {
      int value = pnode->m_nValue;
      ListNode* pnext = NULL;
      ListNode* pdel  = pnode;
      while (pdel != NULL && 
            pdel->m_nValue == value)
      {
        pnext = pdel->m_pNext;

        delete pdel;
        pdel = NULL;

        pdel = pnext;
      }

      if (pprenode == NULL)
      {
        *pphead = pnext;
      }
      else
      {
        pprenode->m_pNext = pnext;
      }
      pnode = pnext; //need to care
    }
  }
}

void DeleteDuplication_1(ListNode** pphead)
{
  if (pphead == NULL | *pphead == NULL)
    return;
  
  bool dup_flag = false;
  ListNode* pprenode = nullptr;
  ListNode* pnode = *pphead;
  
  while (pnode != NULL)
  {
    ListNode* pnext_node = pnode->m_pNext;
    
    if (pnode->m_pNext == NULL)
    {
      if (pprenode != NULL)
      {
        pprenode->m_pNext = pnode;
        pprenode->m_pNext->m_pNext = NULL;
      }
      else
      {
        if (dup_flag != true)
        {
          pprenode = pnode;
          *pphead = pprenode;
        }
        else
        {
          if (pprenode == NULL)
          {
            pprenode = pnode;
            *pphead = pprenode;
            pprenode->m_pNext = NULL;
          }
        }
      }
      break;
    }

    if (pnode->m_nValue != pnext_node->m_nValue)
    {
      if (dup_flag != true)
      {
        if (pprenode != NULL)
          pprenode->m_pNext = pnode;
        else
        {
          pprenode = pnode;
          *pphead = pprenode;
        }

        pprenode = pnode;
        pnode = pnext_node;
      }
      else
      {
        dup_flag = false;
        //pnode = pnext_node;
      }
    }
    else //del the node with the same value  
    {
      int value = pnode->m_nValue;
      ListNode* pnext = NULL;
      ListNode* pdel  = pnode;
      while (pdel != NULL && 
            pdel->m_nValue == value)
      {
        pnext = pdel->m_pNext;

        delete pdel;
        pdel = NULL;

        pdel = pnext;
      }

      pnode = pnext;
      dup_flag = true;
    }
  }

  if (pprenode == NULL)
  {
    *pphead = pprenode;
  }
  else
  {
    if (pnode == NULL)
      pprenode->m_pNext = NULL;
  }
}


// ====================测试代码====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
    {
        printf("FAILED.\n");
        pNode = *pHead;
        while(pNode != NULL)
        {
            printf("the value is %d.\n", pNode->m_nValue);
            pNode = pNode->m_pNext;
        }
    }
}

// 某些结点是重复的
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 没有重复的结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 所有结点的值都相同
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 所有结点都成对出现
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有一个结点
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 空链表
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}
