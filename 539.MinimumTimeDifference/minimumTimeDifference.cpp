# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int calculateMinute(std::string timePoint) {
        int h = 0, m = 0;
        h = h * 10 + timePoint[0] - '0';
        h = h * 10 + timePoint[1] - '0';
        h *= 60;
        m = m *10 + timePoint[3] - '0';
        m = m *10 + timePoint[4] - '0';

        return h + m;
    }
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        std::vector<int> mn(size);
        for (int i = 0; i < size; i++) {
            if (timePoints[i][0] == '0' && timePoints[i][1] == '0') {
                timePoints[i][0]= '2';
                timePoints[i][1]= '4';
            }
            mn[i] = calculateMinute(timePoints[i]);
        }
        sort(mn.begin(), mn.end());
        int ans = 1e9;
        for (int i = 1; i < size; i++) {
            ans = min(ans, mn[i] - mn[i - 1]);
        }
        int circular_diff = 1440 - mn[size - 1] + mn[0];
        return min(ans, circular_diff);
    }
};