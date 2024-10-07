


# include <iostream>
# include <string>
# include <stack>

using namespace std;

/************* __FIRST__SOLUTION__ *************/

//  int minLength(string s) {
        // bool x = 0;
        // for (int i = 0 ; true; i++) {
        //     if (i + 1 < s.size()) {
        //         if (s[i] == 'A' && s[i + 1] == 'B') {
        //             s.erase(i , 2);
        //             x = 1;
        //         }
        //         else if (s[i] == 'C' && s[i + 1] == 'D'){
        //             s.erase(i , 2);
        //             x = 1;
        //         }
        //     }
        //     if (i + 1 >= s.size()) {
        //         if (x == 0) break;
        //         x = 0;
        //         i = -1;
        //     }
        // }
        // return s.size()
    // }

/************* __OPTIMIZATION__SOLUTION__ *************/

class Solution {
public:
    int minLength(string s) {
        std::stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && ((stk.top() == 'A' && s[i] == 'B') || (stk.top() == 'C' && s[i] == 'D') ))
                stk.pop();
            else stk.push(s[i]);
        }
        return stk.size();
    }
};