// https://leetcode.com/problems/check-knight-tour-configuration/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<vector<int>> &grid, int n, int r, int c, int nextVal)
{
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != nextVal)
    {
        return false;
    }
    if (nextVal == (n * n) - 1)
    {
        return true;
    }

    bool ans1 = isValid(grid, n, r + 1, c - 2, nextVal + 1);
    bool ans2 = isValid(grid, n, r + 2, c - 1, nextVal + 1);
    bool ans3 = isValid(grid, n, r + 2, c + 1, nextVal + 1);
    bool ans4 = isValid(grid, n, r + 1, c + 2, nextVal + 1);
    bool ans5 = isValid(grid, n, r - 1, c + 2, nextVal + 1);
    bool ans6 = isValid(grid, n, r - 2, c + 1, nextVal + 1);
    bool ans7 = isValid(grid, n, r - 2, c - 1, nextVal + 1);
    bool ans8 = isValid(grid, n, r - 1, c - 2, nextVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    return isValid(grid, n, 0, 0, 0);
}

int main()
{

    return 0;
}