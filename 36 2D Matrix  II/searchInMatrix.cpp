// https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
using namespace std;
bool searchRow(vector<vector<int>> &matrix, int target, int row)
{
    int start = 0, end = matrix[row].size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target < matrix[row][mid])
        {
            end = mid - 1;
        }
        else if (target > matrix[row][mid])
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int s = 0, e = m - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][n - 1])
        {
            return searchRow(matrix, target, mid);
        }

        else if (target > matrix[mid][n - 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}
int main()
{

    return 0;
}