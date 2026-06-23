// https://leetcode.com/problems/permutations/submissions/2043752645/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPermutation(vector<int> &arr,vector<vector<int>> &ans,int i){
    if (i == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        swap(arr[i],arr[j]);
        getPermutation(arr,ans,i+1);

        swap(arr[i],arr[j]);
        
    }
    
}
vector<vector<int>> permute(vector<int> &arr)
{
    
    vector<vector<int>> ans;
    getPermutation(arr, ans, 0);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}