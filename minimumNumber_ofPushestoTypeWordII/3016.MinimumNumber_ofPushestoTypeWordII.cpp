# include <iostream>
# include <map>
# include <vector>
# include <utility>

using namespace std;


bool comp(std::pair<char , int> &a, std::pair<char , int> &b) {
    return a.second > b.second;
}
class Solution {
public:
    int minimumPushes(string word) {
        std::map<char , int> freq;
        for (int i = 0; i < word.size(); i++)
            freq[word[i]]++;
        std::vector<pair<char , int> > copyFreq(freq.begin(), freq.end());
        sort(copyFreq.begin(), copyFreq.end(), comp);
        int ans = 0;
        int count = 1;
        int calc = 0;
        for (auto key : copyFreq) {
            if (calc == 8) {
                count++;
                calc = 0;
            }
            ans += count * key.second;
            calc++;
        }
        return ans;
    }
};