#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans = {};
    for (int i = 0; i < nums.size(); i++)
    {
        int curr =1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j=!i)   
            {
                curr*=nums[j];
            }
        }
        ans.push_back(curr);
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(vec);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}