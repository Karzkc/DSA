#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10); // insert
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << '\n';
    cout << "Back: " << q.back() << '\n';
    cout << "Size: " << q.size() << '\n';

    q.pop(); // remove front
    cout << "After pop: " << q.front() << '\n';
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << '\n';

    return 0;
}