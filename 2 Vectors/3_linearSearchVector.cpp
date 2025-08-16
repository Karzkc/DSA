#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> &nums, int x)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << linear_search(vec, 10);

    return 0;
}