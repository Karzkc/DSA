#include <iostream>
#include <deque>
using namespace std;




int main()
{
    // ------------------- Declaration -------------------
    deque<int> dq = {10, 20, 30}; // Initializer list

    // ------------------- Insert elements -------------------
    dq.push_back(40);   // Insert at end
    dq.push_front(5);   // Insert at front
    dq.insert(dq.begin() + 2, 15); // Insert at position (index 2)

    cout << "After insertions: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    // ------------------- Access elements -------------------
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "At(2): " << dq.at(2) << endl;

    // ------------------- Size and capacity -------------------
    cout << "Size: " << dq.size() << endl;
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

    // ------------------- Delete elements -------------------
    dq.pop_back();   // Remove last
    dq.pop_front();  // Remove first
    dq.erase(dq.begin() + 1); // Erase element at position

    cout << "After deletions: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    // ------------------- Iterators -------------------
    cout << "Forward iteration: ";
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Reverse iteration: ";
    for (deque<int>::reverse_iterator rit = dq.rbegin(); rit != dq.rend(); ++rit)
        cout << *rit << " ";
    cout << "\n";

    // ------------------- Clear -------------------
    dq.clear();
    cout << "Deque cleared. Size: " << dq.size() << endl;

    return 0;
}
