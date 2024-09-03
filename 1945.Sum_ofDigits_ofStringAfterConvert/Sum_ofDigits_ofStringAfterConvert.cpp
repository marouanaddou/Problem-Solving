
# include <iostream>
# include <string>
using namespace std;


class Solution {
public:
    void convert(std::string &s) {
        std::string str = "";
        for (int i = 0; i < s.size(); i++) {
            str += to_string(s[i] - 96);
        }
        s = str;
    }

    void sum(std::string &s) {
        std::string str = "";
        long long nb = 0;
        for (int i = 0; i < s.size(); i++) {
            nb += s[i] - '0';
        }
        s = to_string(nb);
    }
    
    int getLucky(string s, int k) {
        convert(s);
        for (; s.size() > 1 && k > 0; k--) {
            sum(s);
        }
        return stoi(s);
    }
};