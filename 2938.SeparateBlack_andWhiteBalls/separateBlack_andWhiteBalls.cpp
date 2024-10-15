
# include <iostream>
# include <string>

using namespace std;


class Solution {
public:
    long long minimumSteps(string s) {
        int left = 0, right = 1;
        long long count = 0;
        for (;right < s.size(); right++) {
            if (s[left] == '1' && s[right] == '0') {
                swap(s[left], s[right]);
                left += 1;
                count += right - left + 1;
            }
            else if (s[left] == '0') left += 1;
        }
        return count;
    }
};