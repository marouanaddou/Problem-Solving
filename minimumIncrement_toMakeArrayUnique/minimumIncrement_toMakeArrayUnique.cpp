
# include <vector>
# include <algorithm>



class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        int count = 0;
        if (is_sorted(nums.begin(), nums.end()) == false)
            sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() ;i++)
        {
            if (nums[i] <= nums[i - 1] + 1)
            {
                count += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return count;
    }
};