
# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string compressedString(string word) 
    {
        std::string ans;
        int count;
        int n  = word.size();
        for ( int i = 0; i < n; i++ ) {
            int j  = i;
            for ( ; word[i] == word[j + 1] && j + 1< n; j++ );
            count = j - i + 1;
            if ( count > 9 ) {
                int div = count / 9;
                int mod = count % 9;
                while ( div ){
                    ans += 9 + '0';
                    ans += word[i];
                    div--;
                }
                if ( mod != 0) {
                    ans += mod + '0';
                    ans += word[i];
                }
            }
            else {
                ans += count + '0';
                ans += word[i];
            }
            i = j;
        }
        return ans;
    }
};