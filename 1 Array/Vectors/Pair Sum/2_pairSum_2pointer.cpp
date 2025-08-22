#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int num : pairSum(vec, 7))
    {
        cout << num << " ";
    }

    return 0;
}