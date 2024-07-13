
#include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    static bool compareFirstElement(const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        if (directions.find("R") == -1 || directions.find("L") == -1)
            return healths;
        std::stack<int> stk;
        std::vector<std::vector<int>> robot;
        for (int i = 0; i < positions.size(); i++)
            robot.push_back({positions[i], i, healths[i], directions[i]});
        int idx;
        std::sort(robot.begin(), robot.end());
        for(int i = 0; i < robot.size(); i++)
        {
            if (robot[i][3] == 82 || stk.empty())
            {
                std::cout << i << std::endl;
                stk.push(i);
                continue;
            }
            bool add = 1;
            while(!stk.empty() && add == 1 && robot[stk.top()][3] != 'L')
            {
                idx = stk.top();
                if (robot[i][2] > robot[idx][2])
                {
                    stk.pop();
                    robot[i][2] -= 1;
                }
                else if (robot[i][2] < robot[idx][2])
                {
                    robot[idx][2] -= 1;
                    add = 0;
                }
                else
                {
                    add = 0;
                    stk.pop();
                }
            }
            if (add == 1)
                stk.push(i);
        }
        int n = stk.size();
        std::vector<std::vector<int>> pos;
        for (;!stk.empty();)
        {
            pos.push_back({robot[stk.top()][1], stk.top()});
            stk.pop();
        }
        sort(pos.begin(), pos.end(), compareFirstElement);
        std::vector<int> ans(n);
        for(int i = 0; i < pos.size(); i++)
            ans[i] = robot[pos[i][1]][2];
        return ans;
    }
};