#include <iostream>
#include <utility> // For std::pair
#include <tuple>   // For std::tie
using namespace std;

int main()
{
    // 1. Creating a pair using default constructor
    pair<int, string> p1;
    p1.first = 1;        // Assigning value to first element
    p1.second = "Apple"; // Assigning value to second element

    pair<string, string> p0 = {"name", "karz"};
    // nested pair
    pair<int, pair<int, int>> npair(1, pair<int, int>(2, 3));
    cout << npair.second.first << endl;
    // 2. Creating a pair using parameterized constructor
    pair<int, string> p2(2, "Banana");

    // 3. Creating a pair using make_pair
    pair<int, string> p3 = make_pair(3, "Cherry");

    // 4. Accessing elements of pair
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;
    cout << "p3: " << p3.first << ", " << p3.second << endl;

    // 5. Copying a pair
    pair<int, string> p4 = p2;
    cout << "p4 (copy of p2): " << p4.first << ", " << p4.second << endl;

    // 6. Swapping pairs
    p1.swap(p2); // Swaps contents of p1 and p2
    cout << "After swap, p1: " << p1.first << ", " << p1.second << endl;
    cout << "After swap, p2: " << p2.first << ", " << p2.second << endl;

    // 7. Comparing pairs (lexicographical comparison)
    if (p3 > p4)
    {
        cout << "p3 is greater than p4" << endl;
    }
    else
    {
        cout << "p3 is not greater than p4" << endl;
    }

    // 8. Assigning new values using tie (C++11 and above)
    int num;
    string fruit;
    tie(num, fruit) = p3; // Unpacks p3 into num and fruit
    cout << "Unpacked p3: " << num << ", " << fruit << endl;

    // 9. Structured bindings (C++17 and above)
#if __cplusplus >= 201703L
    auto [id, name] = p4;
    cout << "Structured binding p4: " << id << ", " << name << endl;
#endif

    return 0;
}

/*
Summary of std::pair methods and usage:
1. pair<T1, T2> p;                // Default constructor
2. pair<T1, T2> p(a, b);          // Parameterized constructor
3. make_pair(a, b);               // Factory function
4. p.first, p.second;             // Access elements
5. p1 = p2;                       // Copy assignment
6. p1.swap(p2);                   // Swap contents
7. Relational operators: ==, !=, <, >, <=, >=
8. tie(a, b) = p;                 // Unpack pair (C++11+)
9. auto [a, b] = p;               // Structured binding (C++17+)
*/