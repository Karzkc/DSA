#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // vector initialization with values
    vector<int>
        v2 = {10, 20, 30};

    // Declaration with size and default value
    vector<int> v3(5, 100); // 5 elements, each initialized to 100
    // Declaration of a vector of integers
    vector<int> v1;

    // Declaration an
    // Copy constructor
    vector<int> v4(v2);

    // Assigning values using assign()
    vector<int> v5;
    v5.assign(3, 7); // 3 elements, each initialized to 7

    // Accessing elements using at() and []
    int first = v2[0];
    int second = v2.at(1);

    // Adding elements at the end
    v1.push_back(5);

    // Removing last element
    v1.pop_back();

    // Getting size of vector
    size_t sz = v2.size();

    // Checking if vector is empty
    bool empty = v2.empty();

    // Clearing all elements
    v2.clear();

    // Iterating over a vector
    for (size_t i = 0; i < v3.size(); ++i)
    {
        cout << v3[i] << " ";
    }
    cout << endl;

    // Using iterator
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using range-based for loop (C++11 and above)
    for (int val : v3)
    {
        cout << val << " ";
    }
    cout << endl;

    // for first value 
    cout << v2.front(); 
    cout << v2.back(); 
    cout << v2.capacity(); 
    return 0;
}