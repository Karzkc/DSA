// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0, col = n - 1;
    while (row <= col)
    {
        int mid = n - 1;
        if (target == matrix[row][col])
        {
            return true;
        }

        else if (target > matrix[row][col])
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}
int main()
{

    return 0;
}