// 面试题33_1：二叉搜索树的后序遍历序列 转化为中序遍历

#include "../Utilities/BinaryTree.h"
#include "../Utilities/offer.h"
#include <exception>
#include <cstdio>

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
    // 前序遍历序列的第一个数字是根结点的值
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

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception(/*"Invalid input."*/);

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, 
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}

void post_to_in_first(int arr[], int length)
{
	int i = 0;
	int mid = 0;
	int cur = 0;
	int tmp = 0;

	if (length == 1 || length == 0 || arr == NULL) //the edge and exception
	{
		return;
	}

	int root = arr[length - 1];
	
	for (i = 0; i < length; i++)
	{
		if (arr[i] > root)
		{
			mid = i;
			break;
		}
		mid = i; // the past bugfix 
	}

	cur = root;
	for (i = mid; i < length; i++)
	{
		tmp = arr[i];
		arr[i] = cur;
		cur = tmp;
	}

	if (mid > 0)
		post_to_in_first(arr, mid);

	if (mid < length - 1)
		post_to_in_first(arr + mid + 1, length - mid - 1); // the bugfix: arr + mid + 1
}

void post_to_in(int arr[], int length)
{
  if (arr == NULL || length <= 1)
  {
    return;
  }

  int root = arr[length - 1];
  int i = 0;
  for (i = 0; i < length - 1; i++)
  {
    if (arr[i] > root)
      break;
  }

  int j = i;
  int cur = root;
  for (j = i; j < length; j++)
  {
    int tmp = arr[j];
    arr[j] = cur;
    cur = tmp;
  }

  if (i > 0)
  {
    post_to_in(arr, i);
  }

  if (length > i + 1)
  {
    post_to_in(arr + i + 1, length - i - 1);
  }
}

void post_to_in_interface(int* postorder, int length)
{
  return post_to_in(postorder, length);
}

// ====================测试代码====================
void Test(char* testName, int* postorder, int* real,int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The posorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", postorder[i]);
    printf("\n");

    printf("The real inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", real[i]);
    printf("\n");

    post_to_in_interface(postorder, length);

    printf("The inordered sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", postorder[i]);
    printf("\n");

}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    const int length = 7;
    int inorder[length] = {4, 6, 8, 10, 12, 14, 16};
	  int post [length]   = {4, 8, 6, 12, 16, 14, 10};
	
    Test("Test1", post, inorder, length);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    const int length = 4;
    int inorder[length] = {4, 5, 6, 7};
	int post [length]   = {4, 6, 7, 5};
	
    Test("Test2", post, inorder, length);
}

// 所有结点都没有左子结点
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
    int inorder[length] = {1, 2, 3, 4, 5};
    int post[length]    = {5, 4, 3, 2, 1};	

    Test("Test3", post, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int inorder[length] = {1};
    int post[length] = {1};

    Test("Test4", post, inorder, length);
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
void Test5()
{
    const int length = 5;
    int inorder[length] = {1, 2, 3, 4, 5};
    int post[length] = {1, 2, 3, 4, 5};

    Test("Test5", post, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
#if 0
void Test7()
{
    const int length = 7;
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};
    //int post[length] = {4, 5, 2, 6, 7, 3, 1};
	
    Test("Test7: for unmatched input", preorder, inorder, length);
}
#endif

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    //Test7();

    return 0;
}

