
# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    bool comp(std::string &a , std::string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        std::vector<string> str(size);
        for (int i = 0; i < size; i++) {
            str[i] = to_string(nums[i]);
        }
        std::string ans = "";
        for (int i = 0 ;i < str.size(); i++) {
            for (int j = i + 1 ; j < str.size(); j++) {
                if (comp(str[i], str[j]) == false) {
                    swap(str[i], str[j]);
                }
            }
        }
        if (str[0][0] == '0') return "0";
        for (int i = 0; i < size; i++) {
            ans += str[i];
        }
        return ans;
    }
};