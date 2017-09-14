// Source : https://leetcode.com/problems/summary-ranges/
// Author : Hao Chen
// Date   : 2015-07-03

/********************************************************************************** 
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

#if 0
class Solution {
public:
    string makeRange(int start, int end) {
        ostringstream oss;
        if (start != end) {
            oss << start << "->" << end;
        } else {
            oss << start;
        }
        return oss.str();
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len == 0) return result;
        
        // we have two pointer for range-starter and range-ender
        int start=nums[0], end=nums[0];

        for (int i=1; i<len; i++) {
            // if it is continous number, move the end pointer;
            if (nums[i] == end + 1) {
                end = nums[i];
                continue;
            }
            
            //if the number is not continous, push the range into result
            //and reset the start and end pointer
            result.push_back(makeRange(start, end));
            start = end = nums[i];
        
        }
        
        //for the last range
        result.push_back(makeRange(start, end)); 
        
        return result;
    }
};

#else
class Solution {
public:
  string makeRange(int start, int end)
  {
    ostringstream oss;
    if (start != end) {
      oss << start << "->" << end;
  	} else {
      oss << start;
    }
    return oss.str();
  }

  vector<string> summaryRanges(vector<int>& nums)
  {
    std::vector<string> strs;
		if (nums.size() == 0)
			return strs;

		int min = nums[0];
  	int max = nums[0];
  	bool continue_flag = false;
  	
		int i = 0;
		for (i = 0; i < nums.size(); i++)
		{
			continue_flag = false;
			min = nums[i];
			max = nums[i];
			
			if ((i < nums.size() - 1)&&(nums[i] + 1 == nums[i + 1]))
			{
				continue_flag = true;
			}

			if (continue_flag != true)
			{
				strs.push_back(makeRange(nums[i], nums[i]));
			}
			else
			{
				while (nums[i] + 1 == nums[i + 1])
				{
					max = nums[i + 1];
					i++; // bug trap: the position
				}
				strs.push_back(makeRange(min, max));
			}
		}

		return strs;
  }
  
};


#endif
