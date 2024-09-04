
#include <iostream>
#include <utility>
# include <victor>

using namespace std;

class Solution {
public:
    std::vector<std::pair<int, std::pair<int, int>>> is;
    int count;
    int ans;
    void bfs(vector<vector<int>>& grid2, int i, int j, int count) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[i].size() || grid2[i][j] == 0 || grid2[i][j] == 2) 
            return;
        is.push_back({count, {i, j}});
        if (grid2[i][j] == 1 ) grid2[i][j] = 2;
        bfs(grid2, i, j + 1, count);
        bfs(grid2, i, j - 1, count);
        bfs(grid2, i + 1, j, count);
        bfs(grid2, i - 1,j , count);
    }
    bool checkExist(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &i, int count) {
        for (; i < is.size(); i++) {
            if (count == is[i].first) {
                if (grid1[is[i].second.first][is[i].second.second] != 1) return 0;
            }
            if (is[i].first == count + 1) {
                i--;
                break;
            }
        }
        return 1;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        count = 1;
        ans = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] == 1) {
                    bfs(grid2, i, j, count);
                    count++;
                }
            }
        }
        count = 1;
        for (int i = 0; i < is.size(); i++) {
            ans += checkExist(grid1, grid2, i, count);
            for (;i < is.size() && is[i + 1].first == count; i++);
            count++;
        }
        return ans;
    }
};