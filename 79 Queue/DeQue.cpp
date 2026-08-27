#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.emplace_back(30);
    dq.emplace_front(40);
    dq.insert(dq.begin() + 2, 25);

    cout << "Front: " << dq.front() << '\n';
    cout << "Back: " << dq.back() << '\n';
    cout << "Index 2: " << dq[2] << '\n';
    cout << "At 1: " << dq.at(1) << '\n';

    for (int x : dq)
        cout << x << ' ';
    cout << '\n';

    dq.pop_front();
    dq.pop_back();
    dq.erase(dq.begin() + 1);

    cout << "Size: " << dq.size() << '\n';
    cout << "Empty: " << boolalpha << dq.empty() << '\n';
    dq.clear();

    return 0;
}