#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int majority = floor(nums.size() / 2);
    for (int i = 0; i < nums.size(); i++)
    {
        int count=0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count >= majority)
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {3,2,3};
    cout << majorityElement(vec);

    return 0;
}