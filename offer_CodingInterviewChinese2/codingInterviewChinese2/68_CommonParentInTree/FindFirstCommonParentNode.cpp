#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

struct TreeNode 
{
    int m_nValue;
    TreeNode *m_pLeft;
    TreeNode *m_pRight;
};

//�ٶ��������Ķ���������ͼ��ʾ
/*
           1
        /     \
       2       3
      / \      / 
     4   3    6
    / \   \  / \
   7   8  9  10 11
  /     \
 12      13
        /
       14

*/
void CreateBitree(TreeNode *&pNode, fstream &fin, TreeNode *&pNodeOne, 
                      TreeNode *&PNodeTwo)
{
    int dat;
    fin>>dat;
    if(dat == 0)
    {
        pNode = NULL;
    }
    else 
    {
        pNode = new TreeNode();
        pNode->m_nValue = dat;      
        if (NULL == pNodeOne && !(rand() % 3))
        {
            pNodeOne = pNode;
        }
        if (NULL == PNodeTwo && !(rand() % 5))
        {
            PNodeTwo = pNode;
        }
        CreateBitree(pNode->m_pLeft, fin, pNodeOne, PNodeTwo);      
        CreateBitree(pNode->m_pRight, fin, pNodeOne, PNodeTwo); 
    }
}

//Ѱ�Ҷ���������������͹�ͬ���ڵ�
TreeNode *FindFirstCommonParentNode_org
  (TreeNode *pRoot, TreeNode *pNodeOne, TreeNode *pNodeTwo)
{
    if (NULL == pRoot)
    {
        return NULL;
    }
    if (pRoot == pNodeOne || pRoot == pNodeTwo)
    {
        return pRoot;
    }
    TreeNode *pLeft = FindFirstCommonParentNode_org(pRoot->m_pLeft, pNodeOne, pNodeTwo);
    TreeNode *pRight = FindFirstCommonParentNode_org(pRoot->m_pRight, pNodeOne, pNodeTwo);

    //������û���ҵ��κ�һ����㣬���һ���������ڵ�ض����������������ҵ���һ����������͹�ͬ���ڵ�
    if (NULL == pLeft)
    {
        return pRight;
    }
    //������û���ҵ��κ�һ����㣬���һ���������ڵ�ض����������������ҵ���һ����������͹�ͬ���ڵ�
    else if (NULL == pRight)
    {
        return pLeft;
    }
    else     // �ֱ��ڽ������������ҵ�����˽ڵ��Ϊ��һ���������ڵ�
    {
        return pRoot;
    }
}

TreeNode *FindFirstCommonParentNode
  (TreeNode *pRoot, TreeNode *pNodeOne, TreeNode *pNodeTwo)
{
  if (pRoot == NULL)
    return NULL;

  if (pRoot == pNodeOne || pRoot == pNodeTwo)
    return pRoot;

  TreeNode* pleft  = NULL;
  TreeNode* pright = NULL;

  pleft = FindFirstCommonParentNode(pRoot->m_pLeft, pNodeOne, pNodeTwo);
  pright = FindFirstCommonParentNode(pRoot->m_pRight, pNodeOne, pNodeTwo);  

  if (pleft == NULL)
  {
    return pright;
  }
  if (pright == NULL)
  {
    return pleft;
  }  
  else
  {
    return pRoot;
  }
}

int main()
{
    srand((unsigned)time(NULL));
    fstream fin("tree.txt");
    TreeNode *pRoot = NULL;
    TreeNode *pNodeOne = NULL;
    TreeNode *pNodeTwo = NULL;
    TreeNode *pParent = NULL;
    CreateBitree(pRoot, fin, pNodeOne, pNodeTwo);
    pParent = FindFirstCommonParentNode(pRoot, pNodeOne, pNodeTwo);
    
    cout<<"��һ�����Ϊ��"<<pNodeOne->m_nValue<<endl;
    cout<<"�ڶ������Ϊ��"<<pNodeTwo->m_nValue<<endl;
    cout<<"�׸������Ϊ��"<<pParent->m_nValue<<endl;

    cout<<endl;
    return 0;
}