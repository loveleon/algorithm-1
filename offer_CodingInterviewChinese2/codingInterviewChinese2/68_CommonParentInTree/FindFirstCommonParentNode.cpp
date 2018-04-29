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

//假定所创建的二叉树如下图所示
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

//寻找二叉树两个结点的最低共同父节点
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

    //左子树没有找到任何一个结点，则第一个公共父节点必定在右子树，而且找到第一个结点就是最低共同父节点
    if (NULL == pLeft)
    {
        return pRight;
    }
    //右子树没有找到任何一个结点，则第一个公共父节点必定在左子树，而且找到第一个结点就是最低共同父节点
    else if (NULL == pRight)
    {
        return pLeft;
    }
    else     // 分别在结点的左右子树找到，则此节点必为第一个公共父节点
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
    
    cout<<"第一个结点为："<<pNodeOne->m_nValue<<endl;
    cout<<"第二个结点为："<<pNodeTwo->m_nValue<<endl;
    cout<<"首个父结点为："<<pParent->m_nValue<<endl;

    cout<<endl;
    return 0;
}