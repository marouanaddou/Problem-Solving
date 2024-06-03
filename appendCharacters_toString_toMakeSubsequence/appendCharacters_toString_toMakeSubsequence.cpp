
# include <iostream>

using namespace std;

class Solution 
{
    public:
        int appendCharacters(string s, string t);
};

int Solution::appendCharacters(string s, string t) 
{
    int j = 0;
    int size = t.size();
    for (int i = 0; i < s.size() && j < size; i++)
        if (t[j] == s[i]) j++;
    return size - j;
}
