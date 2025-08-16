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

void swap_minmax(int arr[],int size){
    int min = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>arr[max])
        {
            max = i;
        }
        if (arr[i]<arr[min])
        {
            min = i;
        }       
    }
    swap(arr[max],arr[min]);
    
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
    swap_minmax(arr,size);
    cout << "Swapped Min & Max Values array:" << endl;
    display(arr, size);
    return 0;
}