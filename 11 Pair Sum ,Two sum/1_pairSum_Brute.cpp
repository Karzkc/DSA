#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> vec = {20, 20, 10, 40, 50};
    for (int num : pairSum(vec, 40))
    {
        cout << vec[num] << " ";
    }

    return 0;
}