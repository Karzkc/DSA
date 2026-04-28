#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &arr, int k, int mid)
{

    int cow = 1;
    int stall = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {

        if (-stall + arr[i] >= mid)
        {
            cow++;
            stall = arr[i];
        }
        if (cow==k)
        {
            return true;
        }
        
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int st = 0;
    int end = arr[arr.size() - 1] - arr[0];
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, k, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 4, 8, 9};

    cout << aggressiveCows(vec, 3);

    return 0;
}