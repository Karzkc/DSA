#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // push(): Adds an element to the back of the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // front(): Returns a reference to the front element
    cout << "Front element: " << q.front() << endl; // 10

    // back(): Returns a reference to the last element
    cout << "Back element: " << q.back() << endl; // 30

    // size(): Returns the number of elements in the queue
    cout << "Queue size: " << q.size() << endl; // 3

    // empty(): Checks if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // pop(): Removes the front element
    q.pop(); // Removes 10

    cout << "Front element after pop: " << q.front() << endl; // 20

    // swap(): Swaps the contents of two queues
    queue<int> q2;
    q2.push(100);
    q2.push(200);

    q.swap(q2);

    cout << "After swap, front of q: " << q.front() << endl; // 100
    cout << "After swap, front of q2: " << q2.front() << endl; // 20

    // emplace(): Constructs and inserts element at the end
    q.emplace(300); // Adds 300 to the back

    cout << "Back element after emplace: " << q.back() << endl; // 300

    // Display all elements of queue q
    cout << "Elements in queue q: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}