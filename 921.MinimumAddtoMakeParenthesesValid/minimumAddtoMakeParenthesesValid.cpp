
# include <iostream>
# include <string>
# include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && s[i] == ')' && stk.top() == '(')
                stk.pop();
            else 
                stk.push(s[i]);
        }
        return stk.size();
    }
};