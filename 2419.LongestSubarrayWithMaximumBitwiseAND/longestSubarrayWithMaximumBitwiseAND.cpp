

# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 1;
        int ans = 1, start, k = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
            if (nums[i] == k) {
                start = i;
                for (; i + 1 < size && nums[i] == nums[i + 1]; i++);
                ans = max (ans, i - start + 1);
            }
        }
        return ans;
    }
};
