
# include <iostream>
# include <unordered_map> 
# include <string>
# include <vector>

using namespace std;
            /******************FIRST SOLUTION******************/

// class Solution {
// public:
//     vector<string> split(std::string s) {
//         std::vector<std::string> sp;
//         int pos = 0;
//         int start = 0;
//         for (;pos != -1;) {
//             start = pos;
//             pos = s.find(' ', pos);
//             sp.push_back(s.substr(start, pos - start));
//             if (pos != -1 ) pos++;
//         }
//         return sp;
//     }
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         vector<string> ans;
//         vector<string> sp1 = split(s1);
//         vector<string> sp2 = split(s2);
//         for (int i = 0; i < sp1.size(); i++) {
//             if (count(sp1.begin(), sp1.end(), sp1[i]) == 1 && count(sp2.begin(), sp2.end(), sp1[i]) == 0)
//                 ans.push_back(sp1[i]);
//         }
//         for (int i = 0; i < sp2.size(); i++) {
//             if (count(sp2.begin(), sp2.end(), sp2[i]) == 1 && count(sp1.begin(), sp1.end(), sp2[i]) == 0)
//                 ans.push_back(sp2[i]);
//         }
//         return ans;
//     }
// };

            /******************SECOND SOLUTION******************/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        std::string str = "";
        unordered_map<std::string , int> freq;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                freq[str]++;
                str = "";
            }
            else {
                str.push_back(s1[i]);
            }
        }
        freq[str]++;
        str = "";
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                freq[str]++;
                str = "";
            }
            else {
                str.push_back(s2[i]);
            }
        }
        freq[str]++;
        for (std::unordered_map<std::string , int>::iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second == 1) ans.push_back(it->first);
        }
        return ans;
    }
};