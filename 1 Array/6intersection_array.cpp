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

int intersection(int arr1[], int size1, int arr2[], int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break; // To avoid printing duplicates if arr2 has repeated elements
            }
        }
    }
    cout << endl;
    return 0;
}

int main()
{

    int size1;
    std::cout << "Enter size of array 1 : ";
    std::cin >> size1;
    int *arr1 = new int[size1];
    insert(arr1, size1);

    int size2;
    std::cout << "Enter size of array 2 : ";
    std::cin >> size2;
    int *arr2 = new int[size2];
    insert(arr2, size2);

    std::cout << "Original arrays:" << std::endl;
    std::cout << "Array 1:" << std::endl;
    display(arr1, size1);
    std::cout << "Array 2:" << std::endl;
    display(arr2, size2);

    std::cout << "Intersection of array 1 and 2:" << std::endl;
    intersection(arr1, size1, arr2, size2);

    delete[] arr1;
    delete[] arr2;

    return 0;

}