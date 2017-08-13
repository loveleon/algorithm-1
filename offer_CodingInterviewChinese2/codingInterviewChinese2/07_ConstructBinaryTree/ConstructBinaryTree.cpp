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

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

#include "../Utilities/BinaryTree.h"
#include "../Utilities/offer.h"
#include <exception>
#include <cstdio>

#if 0
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length - 1,
        inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder, 
    int* startInorder, int* endInorder
)
{
    // ǰ��������еĵ�һ�������Ǹ�����ֵ
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception(/*"Invalid input."*/);
    }

    // ������������ҵ�������ֵ
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception(/*"Invalid input."*/);

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // ����������
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, 
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // ����������
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}
#else
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
                                    int* startInorder, int* endInorder)
{
  int root = startPreorder[0];
  BinaryTreeNode* rootnode = new BinaryTreeNode();
  rootnode->m_nValue = root;
  rootnode->m_pLeft = rootnode->m_pRight = NULL;

  if (startPreorder == endPreorder && 
      startInorder == endInorder &&
      *startPreorder == *startInorder)
  {
    return rootnode;
  }

  int leftcount = 0;
  int* rootinorder = startInorder;
  while (rootinorder < endInorder && *rootinorder != root)
  {
    rootinorder++;
    leftcount++;
  }

  if (leftcount > 0)
    rootnode->m_pLeft = ConstructCore(startPreorder + 1, 
                                   startPreorder + leftcount,
                                   startInorder, rootinorder - 1);

  int rightcount =  endInorder - rootinorder;                                
  if (rightcount > 0)
    rootnode->m_pRight = ConstructCore(startPreorder + leftcount + 1, 
                                     endPreorder,
                                     rootinorder + 1, endInorder);
  return rootnode; //need to care
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
  if (preorder == NULL || inorder == NULL || length <= 0)
    return NULL;

  return ConstructCore(preorder, preorder + length - 1, 
                        inorder, inorder + length - 1);
}

#endif

// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// ������������в�ƥ��
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

    return 0;
}

