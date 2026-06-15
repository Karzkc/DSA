// https://leetcode.com/problems/find-the-duplicate-number/description/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicateOnSpace(vector<int> &nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return nums[i];
        }
        s.insert(nums[i]);
    }
    return -1;
}
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
int main()
{

    return 0;
}