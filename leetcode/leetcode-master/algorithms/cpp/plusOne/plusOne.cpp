// Source : https://oj.leetcode.com/problems/plus-one/
// Author : Hao Chen
// Date   : 2014-06-21

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

#if 0
vector<int> plusOne(vector<int> &digits) {
    int carry=1;
    vector <int> v;
    while(digits.size()>0){
        int x = digits.back();
        digits.pop_back();
        x = x + carry;
        v.insert(v.begin(), x%10);
        carry = x/10;
    }
    if (carry>0){
        v.insert(v.begin(), carry);
    }
    return v;

}

void printVector(vector<int>& v)
{
    cout << "{ ";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}


int main()
{
    int a[]={9, 9, 9};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = plusOne(d);
    printVector(v);
    return 0;
}

#else


void printVector(int* v, int len)
{
    cout << "{ ";
    for(int i = 0; i< len; i++){
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int i = 0;
	int carry = 1;
	int sum = 0;
	int rec = 0;

	for (i = digitsSize - 1; i >= 0; i--)
	{
		sum = digits[i] + carry;
		digits[i] = sum % 10;
		carry = sum / 10;
	}

	if (carry > 0)
	{
		//int new_arr[digitsSize + 1];
		int *new_arr = (int *)malloc(sizeof(int) * (digitsSize + 1));
		if (!new_arr)
		{
			return NULL;
		}
		memset(new_arr, 0, digitsSize + 1);
		new_arr[0] = 1;
		memcpy(&new_arr[1], digits, digitsSize);
		*returnSize = digitsSize + 1;
		//printVector(digits, digitsSize);
		return new_arr;
	}
	else
	{
		*returnSize = digitsSize;
		return digits;	
	}
}


int main()
{
    int a[]={9, 9, 9};
    
	int new_l = 0;
	int *new_d = NULL;
	
    new_d = plusOne(a, (sizeof(a)/sizeof(a[0])), &new_l);
    printVector(new_d, new_l);
    return 0;
}

#endif
