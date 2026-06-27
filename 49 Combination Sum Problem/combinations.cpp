// https://leetcode.com/problems/combinations/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combination(int n, int k, vector<vector<int>> &ans, vector<int> &curr, int idx)
{
    if (curr.size() == k)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = idx; i <= n; i++)
    {

        curr.push_back(i);
        combination(n, k, ans, curr, i + 1);
        curr.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> curr;
    combination(n, k, ans, curr, 1);
    return ans;
}
int main()
{

    return 0;
}