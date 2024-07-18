#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) 
    {

        // unordered_map<int,int> map;
        // for (auto num : nums)
        //     map[num]++;
        // sort(nums.begin(), nums.end());
        int pos = 1;
        // for( int i = 0; i < map.size(); i++)
        //     if (map[i] == pos)
        //         pos++;
        return pos;
    }
};
int main(){}