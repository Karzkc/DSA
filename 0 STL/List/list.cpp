#include <iostream>
#include <list>
using namespace std;

int main()
{
    // 1. Create list
    list<int> lst = {10, 20, 30, 40, 50};
    list<int> lst2 = {100, 200};

    // 2. Traversing (forward iterator)
    cout << "Forward traversal: ";
    for (auto it = lst.begin(); it != lst.end(); it++)
        cout << *it << " ";
    cout << endl;

    // 3. Traversing (reverse iterator)
    cout << "Reverse traversal: ";
    for (auto rit = lst.rbegin(); rit != lst.rend(); rit++)
        cout << *rit << " ";
    cout << endl;

    // 4. Front and Back
    cout << "Front: " << lst.front() << ", Back: " << lst.back() << endl;

    // 5. Push and Pop
    lst.push_back(60);
    lst.push_front(5);
    cout << "After push_back(60), push_front(5): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    lst.pop_back();
    lst.pop_front();
    cout << "After pop_back(), pop_front(): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 6. Insert and Erase
    auto it = lst.begin();
    advance(it, 2); // move iterator to 3rd element
    lst.insert(it, 99);
    cout << "After insert(99 at 3rd pos): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    it = lst.begin();
    advance(it, 2);
    lst.erase(it);
    cout << "After erase(3rd element): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 7. Remove by value
    lst.remove(30);
    cout << "After remove(30): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 8. Unique (remove consecutive duplicates)
    lst.push_back(40);
    lst.push_back(40);
    lst.unique();
    cout << "After unique(): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 9. Sort
    lst.push_back(15);
    lst.push_back(3);
    lst.sort();
    cout << "After sort(): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 10. Reverse
    lst.reverse();
    cout << "After reverse(): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 11. Merge two sorted lists
    lst.sort();
    lst2.sort();
    lst.merge(lst2);
    cout << "After merge(lst2 into lst): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 12. Splice (move elements from one list to another)
    list<int> lst3 = {7, 8, 9};
    lst.splice(lst.begin(), lst3); // moves lst3 into lst at beginning
    cout << "After splice(lst3 into lst at begin): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;

    // 13. Clear
    lst3.clear();
    cout << "lst3 size after clear(): " << lst3.size() << endl;

    // 14. Size, Empty
    cout << "lst size: " << lst.size() << ", isEmpty: " << lst.empty() << endl;

    return 0;
}
