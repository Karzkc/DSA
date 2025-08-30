#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int k, int mid)
{

    int painter = 1;
    int wall = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mid < arr[i])
        {
            return false;
        }
        if (wall + arr[i] <= mid)
        {
            wall += arr[i];
        }
        else
        {
            painter++;
            wall = arr[i];
        }
    }
    return painter <= k;
}
int minTime(vector<int> &arr, int k)
{
    int st = 0;
    int end = 0;
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        end += arr[i];
        st = max(arr[i], st);
    }
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {5, 10, 30, 20, 15};

    cout << minTime(vec, 3);

    return 0;
}