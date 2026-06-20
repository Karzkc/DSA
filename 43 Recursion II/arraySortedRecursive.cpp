#include <iostream>
#include <vector>
using namespace std;

bool sorted(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
        return true;
    return arr[n - 1] >= arr[n - 2] && sorted(arr, n - 1);
}

int main()
{
    vector<int> arr= {1,2,3,7,5};
    cout << sorted(arr,5);
    return 0;
}