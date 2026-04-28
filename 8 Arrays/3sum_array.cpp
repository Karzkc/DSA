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



int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    insert(arr,size);
    cout<<"original array:";
    display(arr,size);
    return 0;

}