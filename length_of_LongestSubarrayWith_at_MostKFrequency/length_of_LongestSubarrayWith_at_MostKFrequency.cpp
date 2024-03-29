
# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int, int> dup{};
        int max = 0;
        for ( int start = 0, end = 0; start < nums.size() && end < nums.size(); )
        {
            while (dup[nums[end]] + 1 > k)
                dup[nums[start++]]--;
            if (max < end - start + 1)
                max = end - start + 1;
            dup[nums[end++]]++;
        }
        return max;
    }
};

// int main()
// {
//     vector<int> vec{1,4,4,2};
//     Solution nums;
//     printf ("%d",nums.maxSubarrayLength(vec, 1));
// }