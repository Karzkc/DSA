#include <iostream>

using namespace std;

void display(int arr[], int size)
{
    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i << " : " << arr[i] << endl;
    }
}

int linear_search(int arr[], int size)
{
    int x;
    cout << "Enter Element to Search:- " << endl;
    cin >> x;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
    
}
int main()
{
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Insert value for element: " << i << endl;
        cin >> arr[i];
    }
    display(arr, size);
    cout << linear_search(arr, size);
    return 0;
}