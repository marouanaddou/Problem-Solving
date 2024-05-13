
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findMaxNumber(vector<vector<int> >& grid, int i, int j)
    {
        for (int u = i; u <= grid.size() - 2; u++)
        {
            for (int v = 0; v <= grid[u].size() - 2; v++)
                cout << grid[i][v] << " ";
        }
        return 0;
    }
    vector<vector<int> > largestLocal(vector<vector<int> >& grid) 
    {
        for (int i = 0; i <= grid.size() - 2; i++)
        {
            for (int j = 0; j <= grid[i].size() - 2; j++)
                findMaxNumber(grid, i , j);
            cout << endl;
        }
        return grid;
    }
};
