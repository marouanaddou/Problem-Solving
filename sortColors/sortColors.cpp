
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int zeros , ones;
        zeros = 0; ones = 0;
        for (auto num : nums)
        {
            if (num == 0)
                zeros++;
            else if (num == 1)
                ones++;
        }
        int i = 0;
        for (; i < zeros; i++)
            nums[i] = 0;
        for (; i < zeros + ones;  i++)
            nums[i] = 1;
        for (; i < nums.size(); i++)
            nums[i] = 2;
    }
};