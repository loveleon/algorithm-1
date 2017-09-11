// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 *               
 **********************************************************************************/

#if 0
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto item : nums) {
            if (m.find(item) != m.end()) return true;
            m[item]=true;
        }
        return false;
    }
};

#else

class Solution {
public:
  bool containsDuplicate(vector<int>& nums)
  {
		std::map<int, bool> m;
		
		int i = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) != m.end())
			{
				return true;
			}
			else
			{
				m[nums[i]] = true;
			}
		}

		return false;
  }
};

#endif
