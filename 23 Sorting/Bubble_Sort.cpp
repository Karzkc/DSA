#include <iostream>
#include <vector>
using namespace std;

void bsort(int arr[], int n)
{
    for (int i = 0; i < (n); i++)
    {
        for (int j = 0; j < (n)-i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    bsort(arr, 5);
    cout << "sorted elements: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}