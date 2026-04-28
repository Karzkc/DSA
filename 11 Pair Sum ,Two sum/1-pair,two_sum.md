https://leetcode.com/problems/two-sum/description/

# pair sum

iven an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

## brute force-

```
vector<int> pairSum(vector<int> vec, int target)
{
    vector<int> pairs;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == target)
            {
                pairs.push_back(i);
                pairs.push_back(j);
                return pairs;
            }
        }
    }

}
```

## optimal -two pointer

```
// for sorted array not for hash map
vector<int> pairSum(vector<int> vec, int target)
{
    vector<int> pairs;
    int i = 0;
    int j = vec.size() - 1;
    while (i < j)
    {
        int sum = vec[i] + vec[j];
        if (sum == target)
        {
            pairs.push_back(vec[i]);
            pairs.push_back(vec[j]);
            return pairs;
        }
        else if (sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
    }
    return pairs;
}
```
