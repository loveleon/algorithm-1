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

// ������27���������ľ���
// ��Ŀ�������һ������������һ�����������ú���������ľ���

#include <cstdio>
#include "../Utilities/BinaryTree.h"
#include "../Utilities/offer.h"
#include <stack>

#define FLAG 1

#if 0
void MirrorRecursively(BinaryTreeNode *pNode)
{
    if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr))
        return;

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    
    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);  

    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight); 
}
#else

void MirrorIteratively(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pRoot);

    while(stackTreeNode.size() > 0)
    {
        BinaryTreeNode *pNode = stackTreeNode.top();
        stackTreeNode.pop();

        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if(pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);

        if(pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}

// the org NULL handling is verbose
//    if(... || (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr))
//        return;
//   and 
//    if(pNode->m_pLeft)
//        MirrorRecursively(pNode->m_pLeft);
// can be ignored, all right for the moment
// the follow, performance is better
void MirrorRecursively(BinaryTreeNode *pNode)
{
  if (pNode == NULL)
    return;

  BinaryTreeNode* tmp;
  tmp = pNode->m_pLeft;
  pNode->m_pLeft = pNode->m_pRight;
  pNode->m_pRight = tmp;

  MirrorRecursively(pNode->m_pLeft);
  MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively_my(BinaryTreeNode* pRoot)
{

}

#endif 



// ====================���Դ���====================
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
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

    PrintTree(pNode8);
#if FLAG
    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);
#else
    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
#endif

    DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    PrintTree(pNode8);
#if FLAG
    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);
#else
    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
#endif
    DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    PrintTree(pNode8);
#if FLAG 
    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);
#else
    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
#endif
    DestroyTree(pNode8);
}

// ���Կն������������Ϊ��ָ��
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    PrintTree(pNode);
#if FLAG 
    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);
#else
    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
#endif
}

// ����ֻ��һ�����Ķ�����
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);
#if FLAG 
    printf("=====Test5: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);
#else
    printf("=====Test5: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
#endif
    DestroyTree(pNode8);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

