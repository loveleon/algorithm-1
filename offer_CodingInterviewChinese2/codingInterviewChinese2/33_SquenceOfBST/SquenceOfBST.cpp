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

// ������33�������������ĺ����������
// ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
// ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��

#include <cstdio>
#include "../Utilities/offer.h"

// BST��Binary Search Tree������������
bool VerifySquenceOfBST1(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0)
        return false;

    int root = sequence[length - 1];

    // �ڶ������������������Ľ��С�ڸ����
    int i = 0;
    for(; i < length - 1; ++ i)
    {
        if(sequence[i] > root)
            break;
    }

    // �ڶ������������������Ľ����ڸ����
    int j = i;
    for(; j < length - 1; ++ j)
    {
        if(sequence[j] < root)
            return false;
    }

    // �ж��������ǲ��Ƕ���������
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST1(sequence, i);

    // �ж��������ǲ��Ƕ���������
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST1(sequence + i, length - i - 1);

    return (left && right);
}

// my code
bool be_post(int arr[], int length)
{
	int i = 0;
	int mid = 0;

	if (arr == NULL)
		return false;

	if (length == 1 || length == 0)// the two  choice: or judge pre the func
		return true;
	
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

	i = mid;
	for (i; i < length - 1; i++)
	{
		if (arr[i] <= root)
		{
			return false;
		}
	}

	bool left = true;
	//if (mid > 0) // the past bugfix
		left = be_post(arr, mid);		

	bool right = true;
	//if (mid < length - 1)// the past bugfix
		right = be_post(arr + mid, length - mid - 1);	

	return (left && right);
}


bool VerifySquenceOfBST(int sequence[], int length)
{
	return be_post(sequence, length);
}

// ====================���Դ���====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
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
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
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
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// ����ֻ��1�����
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
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

    return 0;
}

