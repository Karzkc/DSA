#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Declaration
    map<string, int> m;

    // Insertion
    m["apple"] = 2;
    m.insert({"banana", 5});
    m.emplace("orange", 3);

    // Access
    cout << "apple: " << m["apple"] << endl;

    // Iteration
    cout << "All elements:\n";
    for (const auto& pair : m) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Find
    auto it = m.find("banana");
    if (it != m.end()) {
        cout << "Found banana: " << it->second << endl;
    }

    // Erase
    m.erase("apple");

    // Size
    cout << "Size: " << m.size() << endl;

    // Check existence
    if (m.count("orange")) {
        cout << "orange exists\n";
    }

    // Clear
    m.clear();
    cout << "Size after clear: " << m.size() << endl;

    return 0;
}

/*
Key points about map in C++ STL:
- Stores key-value pairs, keys are unique and sorted.
- Underlying data structure: Red-Black Tree (self-balancing BST).
- Time complexity: O(log n) for insert, erase, find.
- Iteration is in sorted order of keys.
- Use unordered_map for faster (average O(1)) access if order is not needed.
*/