# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long long sum = 0;
        for (int i = 0; i < chalk.size(); i++) sum += chalk[i];
        int mod = k % sum;
        for (; i < chalk.size() && mod >= 0 ; i++) {
            if (mod - chalk[i] < 0) return i;
            else mod -= chalk[i];
            if (i + 1 == chalk.size()) i = -1;
        }
        return 0;
    }
};
