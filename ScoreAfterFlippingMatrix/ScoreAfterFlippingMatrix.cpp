
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void changeRow(vector<vector<int>>& grid, int &i, int &sizeCol)
    {
        for (int j = 0; j < sizeCol; j++)
        {
            if (grid[i][j] == 1)
                grid[i][j] = 0;
            else 
                grid[i][j] = 1;
        }
    }

    bool contZeroInCol(vector<vector<int>>& grid, int &j, int &sizeRow)
    {
        int cont = 0;
        for (int i = 0; i < sizeRow;i++)
        {
            if (grid[i][j] == 0)
                cont++;
            if (cont > 2)
                return true;
        }
        return false;
    }

    void changeCol(vector<vector<int>>& grid, int &j, int &sizeRow)
    {
        for (int i = 0; i < sizeRow; i++)
        {
            if (grid[i][j] == 1)
                grid[i][j] = 0;
            else 
                grid[i][j] = 1;
        }
    }

    int calculScoreInRow(vector<vector<int>>& grid, int &i, int &size)
    {
        int bin = size - 1;
        int score = 0;
        for (int j = 0; j < size; j++)
        {
            score += (grid[i][j] * pow(2, bin));
            bin--;
        }
        return score;
    }
    int matrixScore(vector<vector<int>>& grid)
    {
        int res = 0;
        int sizeCol = grid[0].size();
        int sizeRow = grid.size();
        for (int i = 0; i < sizeRow; i++)
            if (grid[i][0] == 0)
                changeRow(grid, i, sizeCol);
        for (int i  = 0; i < sizeRow; i++)
            res += calculScoreInRow(grid, i, sizeCol);
        cout << res << endl;
        for (int j = 0; j < sizeCol; j++)
            if (contZeroInCol(grid, j, sizeRow) == true)
                changeCol(grid, j, sizeRow);
        for (int i = 0; i < sizeRow; i++)
        {
            for (int j = 0; j < sizeCol; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        int res1 = 0;
        for (int i  = 0; i < sizeRow; i++)
            res1 += calculScoreInRow(grid, i, sizeCol);
        cout << res << endl;
        if (res1 > res)
            return res1;
        return res;
    }
};