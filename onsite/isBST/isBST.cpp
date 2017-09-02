/*
��Ŀ����

��ʵ��һ�����������һ�ö������Ƿ�Ϊ�����������
�������ĸ����ָ��TreeNode* root���뷵��һ��bool����������Ƿ�Ϊ�����������
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

/*�������ڵ����ݽṹ*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

const int flag = INT_MAX;
int lastVal = INT_MIN; 
TreeNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeNode *root = new TreeNode(nums[0]);
	queue<TreeNode *> que;
	que.push(root);
	//�������Ԫ�ظ�������Ӧ����������ڵ����
	int size = nums.size();
	for (int i = 1; i < size; i += 2)
	{
		//������׽ڵ����������
		TreeNode *tmp = que.front();
		TreeNode *left = NULL, *right = NULL;
		//����ǿ�������
		if (nums[i] != flag)
		{
			left = new TreeNode(nums[i]);
			que.push(left);
		}

		//����ǿ�������
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}

		tmp->left = left;
		tmp->right = right;
		//������ǰ����Ľڵ�
		que.pop();
	}
	return root;
}

class Checker {
public:

	/*����һ�����������������浽���� T(n)=O(n) S(n)=O(n)*/
	void inOrder(TreeNode *root, vector<int> &v)
	{
		if (root == NULL)
			return;
		inOrder(root->left, v);
		v.push_back(root->val);
		inOrder(root->right, v);
	}

	bool checkBST1(TreeNode* root)
	{
		vector<int> ret;
		inOrder(root, ret);
		std::vector<int>::iterator i = ret.begin();
		std::vector<int>::iterator j = ret.begin() + 1;
		for (; j != ret.end(); ++i, ++j)
		{
			if (*j < *i) // the value is *iterator
			{
				return false;
			}
		}

		return true;
	}

	/*��������ʡ�����Կռ䣬������������һ���ڵ�*/

	bool checkBST2(TreeNode* root) {

		// write code here
		if (!root)
			return true;

		/*�ݹ���������*/
		if (!checkBST2(root->left))
			return false;

		/*�Ƚϵ�ǰ�ڵ㣬�������ѱ����ڵ�����ֵ*/
		if (root->val <= lastVal)
			return false;
		lastVal = root->val;

		/*�ݹ���������*/
		if (!checkBST2(root->right))
			return false;
		
		return true;
	}

	/*�������������Сֵ��*/
	bool checkBST3(TreeNode* root) {
		// write code here
		if (!root)
			return true;
		return checkBST3(root, INT_MAX, INT_MIN);
	}
	bool checkBST3(TreeNode *root, int maxVal, int minVal)
	{
		if (!root)
			return true;
		if (root->val < minVal || root->val >= maxVal)
			return false;
		if (!checkBST3(root->left, root->val, minVal) || !checkBST3(root->right, maxVal, root->val))
			return false;
		return true;
	}
};
/*
				7
			6
		4
	2   5
 8 3

*/
int main()
{
 	//levelOrder
	int data[] = { 7, 6, flag, 4, flag, 2, 5, 8, 3, flag, flag, flag, flag, flag, flag };
  vector<int> vectorData;
  for(int i = 0; i < sizeof(data) / sizeof(int); ++ i)
      vectorData.push_back(data[i]);

	TreeNode *root = generateTree(vectorData);

	Checker c;
	bool ret = c.checkBST1(root);

	cout << ret << endl;

	ret = c.checkBST2(root);

	cout << ret << endl;

	ret = c.checkBST3(root);

	cout << ret << endl;

	return 0;
}