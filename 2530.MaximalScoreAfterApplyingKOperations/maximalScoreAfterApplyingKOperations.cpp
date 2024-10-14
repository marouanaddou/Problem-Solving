
# include <iostream>
# include <queue>
# include <vector>
# include <cmath>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int> > maxHeap(nums.begin(), nums.end());

        long long max, newRes, sum = 0;

        for (int i = 0; i < k; i++) {
            max = maxHeap.top();
            maxHeap.pop();
            sum += max;
            newRes = ceil(static_cast<double>(max) / float(3));
            maxHeap.push(newRes);
        }

        return sum;
    }
};