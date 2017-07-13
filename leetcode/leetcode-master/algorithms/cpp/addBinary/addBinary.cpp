// Source : https://oj.leetcode.com/problems/add-binary/
// Author : Hao Chen
// Date   : 2014-07-05

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

#if 0
string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    string result;
    while( alen>0 || blen>0) {
        int abit = alen<=0 ? 0 : a[alen-1]-'0';
        int bbit = blen<=0 ? 0 : b[blen-1]-'0';
        int cbit = carry ? 1 : 0;
        result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1) );
        carry = (abit+bbit+cbit>1);
        alen--; blen--;
    }
    if (carry){
        result.insert(result.begin(), '1');
    }
    return result;
}

int main(int argc, char** argv) 
{
    string a = "11";
    string b = "1";
    if (argc>2){
        a = argv[1];
        b = argv[2];
    }

    cout << a << "+" << b << "=" << addBinary(a, b) << endl;
    
}

#else
// the bad taste to finish the code
// get the Disadvantage in c and get the Advantage of container in c++
//
void ofs_set(char *pc, char c)
{
	memset(pc, c, 1);
}

char* addBinary(char* a, int a_len, char* b, int b_len, int* new_len)
{
	int array = 0;
	int short_l = 0;
	int long_l = 0;
	int i = 0;
	char *store = NULL;

	if (a_len >= b_len)
	{
		short_l = b_len;
		long_l = a_len;
		store = a;
	}
	else
	{
		short_l = a_len;
		long_l = b_len;
		store = b;
	}
	*new_len = long_l;

	for (i = 1; i <= short_l; i++)
	{
		if (a[a_len - i] == '1' && b[b_len - i] == '1')
		{
			if (array > 0) ofs_set(&store[long_l - i], '1');
			else ofs_set(&store[long_l - i], '0');

			array = 1;
		}
		else if ((a[a_len - i] == '1' && b[b_len - i] == '0') 
				|| (b[b_len - i] == '1' && a[a_len - i] == '0'))
		{
			if (array > 0)
			{
				ofs_set(&store[long_l - i], '0');
				array = 1;
			}
			else
			{
				ofs_set(&store[long_l - i], '1');
				array = 0;
			}
		}
		else if ((a[a_len - i] == '0' && b[b_len - i] == '0'))
		{
			if (array > 0) ofs_set(&store[long_l - i], '1');
			else ofs_set(&store[long_l - i], '0');

			array = 0;
		}
	}

	if (array == 0)
		return store;

	for (i = long_l - short_l - 1; (i >= 0 && array > 0); i--)
	{
		if (store[i] == '1')
		{
			ofs_set(&store[i], '0');
			array = 1;
		}
		else
		{
			ofs_set(&store[i], '1');
			array = 0;
		}
	}

	char *new_char = (char *)malloc((long_l + 1));
	memset(new_char, 0, (long_l + 1));
	if (array > 0)
	{
		new_char[0] = '1';
		memcpy(&new_char[1], store, long_l);
	}
	*new_len += 1;

	return new_char;
}

#endif

int main(int argc, char** argv) 
{
    char a[] = {'1', '1'};
    char b[] = {'1', '1', '1'};
	int len = 0;
	char* new_char = NULL;


	new_char = addBinary(a, (sizeof(a) / sizeof(a[0])), b, (sizeof(b) / sizeof(b[0])), &len);	

	for (int i = 0; i < len; i++ )
	{
		cout << new_char[i];
	}
	cout << endl;
}

