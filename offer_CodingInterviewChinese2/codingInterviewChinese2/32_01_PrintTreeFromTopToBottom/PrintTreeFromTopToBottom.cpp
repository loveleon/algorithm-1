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

// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include <cstdio>
#include "../Utilities/BinaryTree.h"
#include "../Utilities/offer.h"
#include <deque>
#include <queue>

// lizhiang 2018/05/08
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;

    BinaryTreeNode *node = NULL;
    std::deque<BinaryTreeNode *> level;
    
    level.push_back(pRoot);
    while (level.size() > 0)
    {
        node = level.front();
        level.pop_front();
        
        if (node != NULL)
            printf("%d ", node->m_nValue);

        if (node->m_pLeft != NULL)
            level.push_back(node->m_pLeft);
        
        if (node->m_pRight != NULL)
            level.push_back(node->m_pRight);
    }
}

void PrintFromTopToBottom_org(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::deque<BinaryTreeNode *> dequeTreeNode;

    dequeTreeNode.push_back(pRoot);

    while(dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d ", pNode->m_nValue);

        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);

        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}

void PrintFromTopToBottom1(BinaryTreeNode* pRoot)
{
  if (pRoot == NULL)
    return;

  std::deque<BinaryTreeNode*> dequebt;
  dequebt.push_back(pRoot);

  while (dequebt.size())
  {
    BinaryTreeNode* pnode = NULL;
    pnode = dequebt.front();
    dequebt.pop_front();
    printf("%d ", pnode->m_nValue);

    if (pnode->m_pLeft)
      dequebt.push_back(pnode->m_pLeft);
    
    if (pnode->m_pRight)
      dequebt.push_back(pnode->m_pRight);
  }
}

// my code
void PrintFromTopToBottom2(BinaryTreeNode* pRoot)
{
	BinaryTreeNode *tmp = NULL;
	std::deque<BinaryTreeNode *> btree_deque;

	if (pRoot == NULL)
	{
		return;
	}

	btree_deque.push_back(pRoot);
	while (btree_deque.size())
	{
		tmp = btree_deque.front();
		printf("%d ", tmp->m_nValue);

		if (tmp->m_pLeft)
		{
			btree_deque.push_back(tmp->m_pLeft);
		}

		if (tmp->m_pRight)
		{
			btree_deque.push_back(tmp->m_pRight);
		}

		btree_deque.pop_front();
	}
}

// my code
void PrintFromTopToBottom3(BinaryTreeNode* pRoot)
{
	BinaryTreeNode *tmp = NULL;
	std::queue<BinaryTreeNode *> btree_que;

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
		}

		if (tmp->m_pRight)
		{
			btree_que.push(tmp->m_pRight);
		}

		btree_que.pop();
	}
}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    PrintFromTopToBottom(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
#if 1    
    Test2();
    Test3();
    Test4();
    Test5();
#endif

   return 0;
}

