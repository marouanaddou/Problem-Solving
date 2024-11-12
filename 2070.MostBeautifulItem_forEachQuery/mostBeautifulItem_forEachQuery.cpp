

# include <iostream>
# include <victor>
# include <map>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        std::map<int, std::vector<int>> item;
        std::vector<int> ans(queries.size());
        sort(items.begin(), items.end());
        for ( auto &key : items ) {
            item[key[0]].push_back(key[1]);
        }
        int mx = 0;
        for ( auto &key : item) {
            int x;
            if (key.second.size() > 1)
                x = *max_element(key.second.begin(), key.second.end());
            else 
                x = key.second[0];
            mx = max(mx, x);
            key.second[0] = mx;
        }
        for ( int i = 0; i < queries.size(); i++ ) {
            auto it = item.lower_bound(queries[i]);
            if ( it == item.end() ) it--;
            else if ( it->first != queries[i] && it != item.begin()) it--;
            if ( it->first <= queries[i])
                ans[i] = it->second[0];
            else ans[i] = 0;
        }
        return ans;
    }
};