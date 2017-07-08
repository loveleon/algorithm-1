// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
string longestCommonPrefix(vector<string> &strs) {
    string word;
    if (strs.size()<=0) return word;
    for(int i=1; i<=strs[0].size(); i++){
        string w = strs[0].substr(0, i);
        bool match = true;
        int j=1;
        for(j=1; j<strs.size(); j++){
            if (i>strs[j].size() || w!=strs[j].substr(0, i) ) {
                match=false;
                break;
            }
        }
        if (!match) {
            return word;
        }
        word = w;
    }
    return word;
}

int main()
{
    const char* s[]={"abab","aba","abc"};
    vector<string> v(s, s+3);
    cout << longestCommonPrefix(v) <<endl;
}

#else

string longestCommonPrefix(const char** strs, int strs_num)
{
	


}

int main()
{
    const char* s[]={"abab","aba","abc"};
    
    cout << longestCommonPrefix(s, 3) <<endl;
}
#endif

