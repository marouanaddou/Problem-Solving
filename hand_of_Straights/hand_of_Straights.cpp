
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int value , min; 
        value = 0; min = -2;
        vector<int>::iterator it;
        if (is_sorted(hand.begin(), hand.end()) != true)
            sort(hand.begin(), hand.end());
        for (;hand.size() != 0 && hand.size() >= groupSize;)
        {
            min = hand[0];
            value = min;
            hand.erase(hand.begin());
            for(int i = 1; i < groupSize; i++)
            {
                value++;
                it = find(hand.begin(), hand.end(), value);
                if (it == hand.end())
                    return false;
                hand.erase(it);
            }
        }
        return hand.size() == 0;
    }
};