
# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        vector< pair<int, int> > pair;
        vector<double> fraction;
        vector<double> sortFraction;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                pair.push_back(std::make_pair(arr[i], arr[j]));
                fraction.push_back((double)arr[i] / arr[j]);
                sortFraction.push_back((double)arr[i] / arr[j]);
            }
        }
        sort(sortFraction.begin(), sortFraction.end());
        int pos = find(fraction.begin(), fraction.end(), (double)sortFraction[k - 1]) - fraction.begin();
        return { pair[pos].first, pair[pos].second};
    }
};