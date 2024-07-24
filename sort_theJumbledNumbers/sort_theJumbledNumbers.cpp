# include <iostream>
# include <vector>
# include <algorithm>
# include <string>

using namespace std;

bool cmp(std::vector<int> &a, std::vector<int> &b)
{
    return a[1] < b[1];
}
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<vector<int> > srt(n, std::vector<int>(2,0));
        for (int i = 0 ; i < n; i++)
        {
            srt[i][0] = nums[i];
            std::string str = to_string(nums[i]);
            for (int j = 0; j < str.size(); j++)
                srt[i][1] = (srt[i][1] * 10) + (mapping[str[j] - '0']);
            
        }
        sort(srt.begin(), srt.end(), cmp);
        for (int i = 0; i < n; i++)
            nums[i] = srt[i][0];
        return nums;
    }
};