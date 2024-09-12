
# include <iostream>
# include <map>
# include <vector>
# include <string>

using namespace std;


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        std::map<char, int> map;
        for (int i = 0; i < allowed.size(); i++) map[allowed[i]]++;
        bool find = true;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            int j = 0;
            find = true;
            for (; j < words[i].size(); j++) {
                if (map.find(words[i][j]) == map.end()){
                    find = false;
                    break;
                }
            }
            if (find == true)
                ans++;
        }
        return ans;
    }
};