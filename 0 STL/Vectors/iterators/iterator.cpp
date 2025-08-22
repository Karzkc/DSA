#include <iostream>
#include <vector>
#include <iterator> // for advance, next, prev
using namespace std;

int main()
{
    // Initialize vector
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << "Original Vector: ";
    for (int x : vec) cout << x << " ";
    cout << "\n\n";

    // 1. Normal Iterator
    cout << "Using begin() to end(): ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << "\n";

    // 2. Reverse Iterator
    cout << "Using rbegin() to rend(): ";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        cout << *rit << " ";
    cout << "\n";

    // 3. Constant Iterator (cannot modify values)
    cout << "Using cbegin() to cend(): ";
    for (vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); cit++)
        cout << *cit << " ";
    cout << "\n";

    // 4. Constant Reverse Iterator
    cout << "Using crbegin() to crend(): ";
    for (vector<int>::const_reverse_iterator crit = vec.crbegin(); crit != vec.crend(); crit++)
        cout << *crit << " ";
    cout << "\n\n";

    // 5. advance(), next(), prev()
    auto it = vec.begin();        // Points to 10
    advance(it, 2);               // Move 2 steps → now points to 30
    cout << "advance(it,2): " << *it << "\n";

    auto it2 = next(it, 2);       // From 30 move 2 → 50
    cout << "next(it,2): " << *it2 << "\n";

    auto it3 = prev(it2, 2);      // From 50 move back 2 → 30
    cout << "prev(it2,2): " << *it3 << "\n\n";

    // 6. Insert using iterator
    it = vec.begin();
    advance(it, 2); // position = 3rd element (30)
    vec.insert(it, 25); // Insert 25 before 30

    cout << "After insert(25 before 30): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";

    // 7. Erase using iterator
    it = vec.begin();
    advance(it, 4); // position = 5th element
    vec.erase(it);  // remove that element

    cout << "After erase(5th element): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";

    // 8. Erase range
    vec.erase(vec.begin()+1, vec.begin()+3); // removes elements at index 1 and 2
    cout << "After erase(begin+1 to begin+3): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";

    return 0;
}
