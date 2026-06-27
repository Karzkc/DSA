// https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combination(vector<int> &arr, int target, vector<vector<int>> &ans,
                 vector<int> &curr, int i)
{

    if (target < 0)
        return;

    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }

    for (int idx = i; idx < arr.size(); idx++)
    {

        if (idx > i && arr[idx] == arr[idx - 1])
            continue;

        curr.push_back(arr[idx]);
        combination(arr, target - arr[idx], ans, curr, idx + 1);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> curr;
    combination(arr, target, ans, curr, 0);
    return ans;
}

int main()
{

    return 0;
}