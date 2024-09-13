
# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    std::vector<int> ans;
    void calculateXOR(vector<int>& arr, int start, int end) {
        int result = arr[start] ^ arr[start + 1];
        start += 2;
        for (;start <= end; start++) {
            result = result ^ arr[start];
        }
        ans.push_back(result);
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int result;
        int start, end;
        for (int i = 0; i < queries.size(); i++) {
            start = queries[i][0];
            end = queries[i][1];
            if ( start == end) ans.push_back(arr[start]);
            else if (start == end) ans.push_back(arr[start] ^ arr[end]);
            else {
                result = arr[start] ^ arr[start + 1];
                start += 2;
                for (;start <= end; start++) {
                    result = result ^ arr[start];
                }
                ans.push_back(result);
            }
        }
        return ans;
    }
};