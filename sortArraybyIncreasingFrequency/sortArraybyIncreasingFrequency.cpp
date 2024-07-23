
# include <iostream>
# include <map>
# include <utility>
# include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first; 
    return a.second < b.second;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::map<int, int> freq;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        std::vector<pair<int, int> > copyFreq(freq.begin(), freq.end());
        sort(copyFreq.begin(), copyFreq.end(), cmp);

        for (auto ele : copyFreq)
            for (int i = 0 ; i < ele.second; i++)
                ans.push_back(ele.first);
        return ans;
    }
};
