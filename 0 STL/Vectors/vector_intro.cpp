#include <iostream>
#include <vector>
#include <algorithm> // for sort, reverse
using namespace std;

int main()
{
    // 1. Declaration
    vector<int> v;                 // empty
    vector<int> v2(5, 10);         // {10,10,10,10,10}
    vector<int> v3 = {1, 2, 3, 4}; // initialized

    cout << "Initial vectors:\n";
    cout << "v2: ";
    for (int x : v2)
        cout << x << " ";
    cout << "\nv3: ";
    for (int x : v3)
        cout << x << " ";
    cout << "\n\n";

    // 2. Adding elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "After push_back: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 3. Accessing elements
    cout << "First element (front): " << v.front() << "\n";
    cout << "Last element (back): " << v.back() << "\n";
    cout << "Element at index 1: " << v.at(1) << "\n\n";

    // 4. Size & Capacity
    cout << "Size: " << v.size() << "\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << "\n\n";

    // 5. Removing elements
    v.pop_back();
    cout << "After pop_back: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 6. Inserting / Erasing
    v.insert(v.begin() + 1, 15); // insert at index 1
    cout << "After insert: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    v.erase(v.begin() + 1); // erase index 1
    cout << "After erase: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 7. Clear all elements
    v.clear();
    cout << "After clear, size: " << v.size() << "\n\n";

    // 8. Other useful functions
    vector<int> nums = {5, 1, 8, 3, 2};
    cout << "Original nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    sort(nums.begin(), nums.end());
    cout << "After sort: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    reverse(nums.begin(), nums.end());
    cout << "After reverse: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    // 9. Swap two vectors
    vector<int> a = {1, 2, 3};
    vector<int> b = {9, 8};
    a.swap(b);

    cout << "After swap:\n";
    cout << "a: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";
    cout << "b: ";
    for (int x : b)
        cout << x << " ";
    cout << "\n";

    return 0;
}
