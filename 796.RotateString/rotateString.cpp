
# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( s.size() != goal.size() ) return false;
        if ( s == goal ) return true;
        int n = goal.size();
        s += s;
        for ( int i = 1; i < n; i++ ) {
            if ( goal.find(s[i]) == -1 ) return false;
            if ( std::equal(s.begin() + i, s.begin() + n , goal.begin()) == true )
                return true;
        }
        return false;
    }
};


// bool rotateString(string s, string goal) {
//     if ( s.size() != goal.size() ) return false;

//     s += s;
//     if (s.find(goal) == -1) return false;
//     return true;
// }
