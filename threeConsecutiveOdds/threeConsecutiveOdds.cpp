
# include <iostream>
# include <vector>

using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int left = 0, right = 0;
        int count = 0;
        for (; right < arr.size(); right++)
        {
            if (arr[right] % 2 == 1)
                count++;
            if (count == 3)
                return true;
            if (right - left + 1 == 3)
            {
                if (arr[left] % 2 == 1)
                    count--;
                left++;
            }
        }
        return false;
    }
};