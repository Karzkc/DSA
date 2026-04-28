#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 1;
    int major = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            count++;
            major = nums[i];
        }
        else{
            count=1;
        }

        if (count>n/2)
        {
            return major;
        }
        
    }
}

int main()
{
    vector<int> vec = {3, 2, 3};
    cout << majorityElement(vec);

    return 0;
}