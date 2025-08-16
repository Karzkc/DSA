#include <iostream>
using namespace std;

void insert(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Insert value for element " << i << ": ";
        cin >> arr[i];
    }
}

void display(int arr[], int size)
{
    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i << " : " << arr[i] << endl;
    }
}

int unique(int arr[], int size)
{
    bool uq;
    for (int i = 0; i < size; i++)
    {
        uq = true;
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                uq = false;
                break;
            }
        }
        if (uq)
        {
            cout << arr[i] << endl;
        }
    }
    if (!uq)
    {
        cout << -1;
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    insert(arr, size);
    cout << "original array:" << endl;
    display(arr, size);
    unique(arr, size);
    return 0;
}