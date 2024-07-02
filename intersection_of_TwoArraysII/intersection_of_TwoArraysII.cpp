
# include <iostream>
# include <vector>


using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        std::vector<int> vec1(1001, 0);
        std::vector<int> vec2(1001, 0);
        int i = 0;
        for(; i < nums1.size(); i++)
            vec1[nums1[i]]++;
        for(i = 0; i < nums2.size(); i++)
            vec2[nums2[i]]++;
        nums1.clear();
        for(i = 0; i < vec1.size(); i++)
        {
            if (vec1[i] > 0 && vec2[i] > 0)
            {
                if (vec1[i] >= vec2[i])
                    for (int j = 0; j < vec2[i];j++)
                       nums1.push_back(i); 
                else 
                    for (int j = 0; j < vec1[i];j++)
                       nums1.push_back(i);
            }
        }
        return nums1;
    }
};