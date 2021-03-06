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

// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。

#include <cstdio>
#include "../Utilities/BinaryTree.h"
#include "../Utilities/offer.h"
#include <queue>

// lizhiang 2018/05/08
void Print(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;

    BinaryTreeNode *node = NULL;
    std::deque<BinaryTreeNode *> dq;
    dq.push_back(pRoot);

    int now = 1;
    int next = 0;

    while (dq.size() > 0)
    {
        node = dq.front();
        printf("%d ", node->m_nValue);

        if (node->m_pLeft != NULL)
        {
            dq.push_back(node->m_pLeft);
            next++;
        }

        if (node->m_pRight != NULL)
        {
            dq.push_back(node->m_pRight);
            next++;
        }
        
        dq.pop_front();
        now--;
        if (now == 0)
        {
            printf("\n");
            now = next;
            next = 0;
        }
    }
}

void Print_org(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while(!nodes.empty())
    {
        BinaryTreeNode* pNode = nodes.front();
        printf("%d ", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
        {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if(pNode->m_pRight != nullptr)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;
        if(toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}

void Print1(BinaryTreeNode* pRoot)
{
  if (pRoot == NULL)
    return;
   
  int nextlevel = 0;
  int tobeprint = 1;
  std::deque<BinaryTreeNode*> dequebt;
  dequebt.push_back(pRoot);
  
  while (dequebt.size())
  {
    BinaryTreeNode* pnode = NULL;
    pnode = dequebt.front();
    printf("%d ", pnode->m_nValue);

    if (pnode->m_pLeft)
    {
      dequebt.push_back(pnode->m_pLeft);
      nextlevel++;
    }
    
    if (pnode->m_pRight)
    {
      dequebt.push_back(pnode->m_pRight);
      nextlevel++;
    }

    dequebt.pop_front();
    --tobeprint;
    if (tobeprint == 0)
    {
      printf("\n");
      tobeprint = nextlevel;
      nextlevel = 0;
    }
  }
}

// my code
void Print2(BinaryTreeNode* pRoot)
{
	BinaryTreeNode *tmp = NULL;
	std::queue<BinaryTreeNode*> btree_que;
	int ref_count = 1;
	int next_level = 0;
	
	if (pRoot == NULL)
	{
		return;
	}

	btree_que.push(pRoot);
	while (btree_que.size())
	{
		tmp = btree_que.front();
		printf("%d ", tmp->m_nValue);

		if (tmp->m_pLeft)
		{
			btree_que.push(tmp->m_pLeft);
			++next_level;
		}

		if (tmp->m_pRight)
		{
			btree_que.push(tmp->m_pRight);
			++next_level;
		}

		btree_que.pop();
		--ref_count;
		if (ref_count == 0)
		{
			printf("\n");
			ref_count = next_level;
			next_level = 0;
		}
	}
}

void Print_interface(BinaryTreeNode* pRoot)
{
	return Print(pRoot);
}

// ====================测试代码====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("6 10 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    Print_interface(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    Print(nullptr);
    printf("\n");
}

//        100
//        /
//       50   
//         \
//         150
void Test6()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    Print(pNode100);
    printf("\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

