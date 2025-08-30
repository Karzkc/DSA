#include <iostream>
#include <vector>
using namespace std;

void ssort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int dihh = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[dihh])
            {
                dihh = j;
            }
        }
        swap(arr[i], arr[dihh]);
    }
}

int main()
{
    int arr[] = {50, 10, 20, 30, 40};

    cout << "Vector elements: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    ssort(arr, 5);
    cout << "sorted elements: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}