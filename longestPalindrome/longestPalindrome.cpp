

# include <iostream>
# include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s);
};

int Solution::longestPalindrome(string s) 
{
    std::map<char , int> frequency;
    int longestOddFrequency = 0;
    int lengthLongestPalindrome = 0;
    for (int i = 0; i < s.size(); i++)
        frequency[s[i]]++;
    for (auto key : frequency)
    {
        if (key.second % 2 == 0)
            lengthLongestPalindrome += key.second;
        else 
        {
            lengthLongestPalindrome += key.second - (key.second % 2);
            if (key.second > longestOddFrequency)
                longestOddFrequency = key.second;
        }
    }
    if (longestOddFrequency > 0)
        lengthLongestPalindrome += longestOddFrequency % 2;
    return lengthLongestPalindrome++;
}
