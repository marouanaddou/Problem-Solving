

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        std::vector<int> copyHeights;
        copyHeights = heights;
        int count = 0;
        sort(copyHeights.begin(), copyHeights.end());
        for (int i = 0; i < copyHeights.size(); i++)
            if (copyHeights[i] != heights[i])
                count++;
        return count;
    }
};