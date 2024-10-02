
# include <iostream>
# include <vector>
# include <map>

using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::map<int, std::vector<int>> pos;
        int n = arr.size();
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
        int j = 1;
        for (auto key : pos) {
            std::vector<int>::iterator it = key.second.begin();
            for (; it != key.second.end(); it++) {
                ans[*it] = j;
            }
            j++;
        }
        return ans;
    }
};




    //  __TIME__LIMIT__ 

// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         std::map<int, int> pos;
//         std::vector<int> ans(arr.size());
//         for (int i = 0; i < arr.size(); i++) {
//             pos[arr[i]]++;
//         }
//         int j = 1;
//         for (auto key : pos) {
//             auto it = arr.begin();
//             for (int i = 0; i < key.second; i++) {
//                 it = find(arr.begin() + (it - arr.begin()), arr.end(), key.first);
//                 ans[it - arr.begin()] = j;
//                 it++;
//             }
//             j++;
//         }
//         return ans;
//     }
// };