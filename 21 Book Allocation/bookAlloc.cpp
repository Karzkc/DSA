#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int k, int mid)
{
    int person = 1;
    int page = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
            return false;

        if (page + arr[i] <= mid)
        {
            page += arr[i];
        }
        else
        {
            person++;
            page = arr[i];
        }
    }

    return person <= k;
}

int findPages(vector<int> &arr, int k)
{
    int n = arr.size();
    int st = 0, end = 0, ans = -1;

    for (int i = 0; i < n; ++i)
    {
        end += arr[i];
        st = max(st, arr[i]);
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
    vector<int> vec = {12, 34, 67, 90};

    cout << findPages(vec, 2);

    return 0;
}