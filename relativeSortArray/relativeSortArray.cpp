
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        int i = 0;
        std::map<int , int> fr;
        for (; i < arr1.size(); i++)
            fr[arr1[i]]++;
        arr1.clear();
        for (i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < fr[arr2[i]]; j++)
                arr1.push_back(arr2[i]);
            fr[arr2[i]] = -1;
        }
        for ( auto key : fr)
            if (key.second != -1)
                for(i = 0; i < key.second; i++)
                    arr1.push_back(key.first);
        return arr1;
    }
};