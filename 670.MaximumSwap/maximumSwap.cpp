
# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        std::string str = to_string(num);
        std::string mx = str;
        for ( int i = 0; i < str.size(); i++ ) {
            for ( int j = i + 1; j < str.size(); j++ ){
                swap( str[i], str[j] );
                mx = max(mx , str);
                swap( str[i], str[j]);
            }
        }
        return stoi(mx);
    }
};