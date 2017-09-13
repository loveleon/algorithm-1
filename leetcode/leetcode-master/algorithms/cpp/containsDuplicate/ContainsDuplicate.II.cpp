// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Hao Chen
// Date   : 2015-06-12

/********************************************************************************** 
 * 
 * Given an array of integers and an integer k, find out whether there there are 
 * two distinct indices i and j in the array such that nums[i] = nums[j] and 
 * the difference between i and j is at most k.
 * 
 *               
 **********************************************************************************/

#if 0
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if (m.find(n) != m.end() && i - m[n] <= k) {
                return true;
            }
            m[n] = i;
        }
        return false;
    }
};

#else

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k)
  {
		std::map<int, int> m; //<num, index>

		int i = 0;
		for (i = 0; i < nums.size(); i++)
		{
			int num = nums[i];
			if ((m.find(num) != m.end()) && i - m[num] <= k)
				return true;

			m[num] = i; 
		}
		
		return false;
  }
};



#endif

/*
test:

[1,2,3,4,1,5]
4
[1,2,3,4,1,5]
5
[1,2,1,4,1,5]
3
[]
0

true
true
true
false


*/
