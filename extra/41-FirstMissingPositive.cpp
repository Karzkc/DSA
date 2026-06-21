#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int mx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        
        
        if (nums[i] < 0 && nums[i]<=nums.size())
        {
            nums[i] = 0;
        }
        
    }
    
    for (int i = 1; i <= mx; i++)
    {
        if (find(nums.begin(), nums.end(), i) == nums.end())
        {
            miss = i;
        }
    }
    return miss;
}
int main()
{

    return 0;
}