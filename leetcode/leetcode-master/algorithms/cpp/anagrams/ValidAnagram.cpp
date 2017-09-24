// Source : https://leetcode.com/problems/valid-anagram/
// Author : Hao Chen
// Date   : 2015-08-16

/********************************************************************************** 
 * 
 * Given two strings s and t, write a function to determine if t is an anagram of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *               
 **********************************************************************************/


class Solution {
public:

    //stupid way - but easy to understand  - 76ms
    bool isAnagram01(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    
    //using a map to count every chars in the string.
    bool isAnagram02(string s, string t) {
        int map[26] ={0} ; //only lowercase alphabets
        //memset(map, 0, sizeof(map));
        
        // count each char for s
        for (int i=0; i<s.size(); i++) {
            map[s[i]-'a']++;
        }
        // decrease the count for t
        for (int i=0; i<t.size(); i++) {
            map[t[i]-'a']--;
        }
        
        //if all alphabets is zero, then they are anagram 
        for (int i=0; i<sizeof(map)/sizeof(map[0]); i++) {
            if (map[i]!=0) return false;
        }
        return true;
    }

#define VEC
  bool isAnagram03(string s, string t)
  {
    int i = 0;
#ifdef VEC
    std::vector<int> v;
    for (i = 0; i < 26; i++)
    {
      //// otherwise: later reference binding to null pointer of type 'value_type'
      //下标只能用于获取已存在的元素，如果不push_back a[i]还是空的对象
      v.push_back(0);
    }
#else
    int v[26] ={0};
#endif

    if (s.size() != t.size())
      return false;

    if (s.size() == 0)
      return true;

    int i = 0;
    for (i = 0; i < s.size(); i++)
    {
      v[s[i] - 'a']++;
    }

    for (i = 0; i < t.size(); i++)
    {
      if (v[t[i] - 'a'] > 0)
        v[t[i] - 'a']--;
      else
        return false;
    }

    return true;
  }
  
    bool isAnagram(string s, string t) {
        return isAnagram02(s,t); //12ms
        return isAnagram01(s,t); //76ms
    }
    
};



