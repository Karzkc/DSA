// https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void combination(vector<int> &arr, int target, vector<vector<int>> &ans,
                 vector<int> &curr, int i)
{

    if (i == arr.size() || target < 0)
    {
        return;
    }

    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }

    curr.push_back(arr[i]);
    combination(arr, target - arr[i], ans, curr, i); // include
    curr.pop_back();                                 // backtrack

    combination(arr, target, ans, curr, i + 1); // exclude
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> curr;
    combination(arr, target, ans, curr, 0);
    return ans;
}

int main()
{

    return 0;
}