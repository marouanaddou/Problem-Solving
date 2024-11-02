
# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    std::vector<std::string> split( std::string sentence ) {
        int pos = 0, begin;
        std::vector<std::string> ans;

        for ( ; pos != -1 ; ) {
            begin = pos;
            pos = sentence.find(" ", pos);
            if ( pos != -1 ) {
                ans.push_back(sentence.substr( begin, pos - begin ));
                pos = pos + 1;
            }
        }
        ans.push_back(sentence.substr( begin));
        return ans;
    }

    bool isCircularSentence(string sentence) {
        std::vector<std::string> words = split( sentence );
        if ( words[0][0] != words[words.size() - 1][words[words.size() - 1].size() - 1] ) {
            return false;
        }

        for ( int i = 1; i < words.size(); i++ ) {
            if ( words[i - 1][words[i - 1].size() - 1] !=  words[i][0] ) 
                return false;
        }
        return true;
    }
};