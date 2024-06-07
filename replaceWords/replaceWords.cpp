

# include <iostream>
# include <string>
# include <vector>
# include <climits>

using namespace std;

class Solution {
public:
    std::vector<std::string> split(std::string s, std::string c)
    {
        std::vector<std::string> vec;
        size_t pos = 0;
        for(;pos < s.size();)
        {
            pos = s.find(c);
            if ((int)pos == -1)
                break;
            vec.push_back(s.substr(0,pos));
            s.erase(0, pos + 1);
            pos = 0;
        }
        vec.push_back(s);
        return(vec);
    }

    int checkExist(std::string word, vector<string>& dictionary)
    {
        int pos = -1;
        int size = INT_MAX;
        for (int i = 0; i < dictionary.size(); i++)
        {
            if (dictionary[i] == word.substr(0, dictionary[i].size()) && dictionary[i].size() < size)
            {
                pos = i;
                size = dictionary[i].size();
            }
        }
        return pos;
    }

    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        std::string result;
        std::vector<std::string> splitSentence = split(sentence, std::string(1, ' '));
        int check;
        for (int i = 0; i < splitSentence.size(); i++)
        {
            if ((check = checkExist(splitSentence[i], dictionary)) != -1)
                result += dictionary[check];
            else 
                result += splitSentence[i];
            if (i + 1 != splitSentence.size())
                result += ' ';

        }
        return result;
    }
};
