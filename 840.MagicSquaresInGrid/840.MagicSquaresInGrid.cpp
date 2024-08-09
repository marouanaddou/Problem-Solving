
# include <vector>

using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == grid[i][j + 1] ||  grid[i][j + 1] == grid[i][j + 2] || grid[i][j] == grid[i][j + 2])
            return 0;
        if (grid[i][j] == grid[i + 1][j] ||  grid[i + 1][j] == grid[i + 2][j] || grid[i][j] == grid[i + 2][j])
            return 0;
        if (grid[i][j] == grid[i + 1][j + 1] ||  grid[i + 1][j + 1] == grid[i + 2][j + 2] || grid[i][j] == grid[i + 2][j + 2])
            return 0;
        if (grid[i][j + 1] == grid[i + 1][j] || grid[i][j + 1] == grid[i + 2][j]
            || grid[i][j + 2] == grid[i + 1][j] || grid[i][j + 1] == grid[i + 2][j]
                || grid[i + 1][j + 1] == grid[i + 1][j] || grid[i + 1][j + 1] == grid[i + 2][j]
                    || grid[i + 1][j + 1] == grid[i][j + 1] || grid[i + 1][j + 1] == grid[i][j + 1]
                        || grid[i + 2][j + 2] == grid[i + 1][j] || grid[i + 2][j + 2] == grid[i + 2][j]
                            || grid[i + 2][j + 2] == grid[i][j + 1] || grid[i + 2][j + 2] == grid[i][j + 1])
                                return 0;
        int row = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        if (row > 15)
            return 0;
        int col = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        if (col > 15)
            return 0;
        int diag = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        if (diag > 15)
            return 0;
        if (row == col && col == diag) {
            std::cout << i << " " << j << std::endl;
            return 1;
        }
        return 0;
    }

    int check(vector<vector<int>>& grid, int i, int j) {
        for (int u = i; u < i + 3; u++) {
            for (int v = j; v < j + 3; v++) {
                if (grid[u][v] == 0)
                    return -1;
            }
        }
        return 0;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (i + 2 >= grid.size())
                break;
            for (int j = 0; j < grid[i].size(); j++) {
                if (j + 2 >= grid[i].size())
                    break;
                if (check(grid, i, j) != -1)
                    ans += solve(grid, i, j);
            }
        }
        return ans;
    }
};