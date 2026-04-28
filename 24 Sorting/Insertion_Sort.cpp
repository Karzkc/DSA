#include <iostream>
#include <vector>
using namespace std;

void isort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
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
    isort(arr, 5);
    cout << "sorted elements: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}