
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    void    remove(string &s, int &i)
    {
        s.erase(i--, 1);
        for (int j = i; i >= 0; j--)
        {
            if (isdigit(s[i]) == 0)
            {
                s.erase(j, 1);
                i--;
                break;
            }
        }
    }
    string clearDigits(string s) 
    {
        int pos = 1;
        for (int i = 0;i < s.size(); i++)
        {
            if (isdigit(s[i]) != 0)
                remove(s, i);
        }
        return s;
    }
};