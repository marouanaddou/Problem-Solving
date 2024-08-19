

# include <iostream>

using namespace std;


class Solution {
public:
    int minSteps(int n) {
        int cnt = 1;
        int pst = 0;
        int ans = 0;
        for (;cnt < n;) {
            if (n % cnt == 0) {
                pst = cnt;
                cnt += cnt;
                ans += 2;
            }
            else {
                ans += 1;
                cnt += pst;
            }
        }
        return ans;
    }
};