
# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        std::string binStart, binGoal;
        for(;start > 0;) {
            if((start & 1) == 1) binStart.push_back('1');
            else binStart.push_back('0');
            start = start >> 1;
        }
        for(;goal > 0;) {
            if((goal & 1) == 1) binGoal.push_back('1');
            else binGoal.push_back('0');
            goal = goal >> 1;
        }
        std::reverse(binStart.begin(), binStart.end());
        std::reverse(binGoal.begin(), binGoal.end());
        int size1 = binStart.size();
        int size2 = binGoal.size();
        if ( size1 > size2) {
            for (int i = 0; i < size1 - size2; i++) {
                binGoal.insert(0,"0");
            }
        }
        else {
            for (int i = 0; i < size2 - size1; i++) {
                binStart.insert(0,"0");
            }
        }
        int ans = 0;
        for (int i = binStart.size() - 1; i >= 0; i--) {
            if (binStart[i] != binGoal[i])
                ans++;
        }
        return ans;
    }
};