// https://leetcode.com/problems/find-missing-and-repeated-values/description/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{

    int n = grid.size();
    long long N = n * n;
    long long sum = N * (N + 1) / 2;
    int gsum = 0;
    int actualSq = 0;
    long long expectedSq = N * (N + 1) * (2 * N + 1) / 6;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            gsum += grid[i][j];
            actualSq += grid[i][j] * grid[i][j];
        }
    }
    int gap = sum - gsum;
    int sqgap = expectedSq - actualSq;
    int a = (gap + sqgap / gap) / 2;
    int b = (sqgap / gap - gap) / 2;
    return {b,a};
}
int main()
{

    return 0;
}