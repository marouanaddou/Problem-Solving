


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        std::vector<long long> ans(nums.size());
        ans[0] = nums[0] + nums[0];
        int mx = nums[0];
        for ( int i = 1; i < nums.size(); i++ ) {
            mx = max(mx, nums[i]);
            ans[i] = ans[i - 1] + nums[i] + mx;
        }
        return ans;
    }
};