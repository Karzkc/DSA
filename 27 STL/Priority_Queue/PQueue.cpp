#include <iostream>
#include <queue> // Include for priority_queue
using namespace std;

int main() {
    // Definition of a max-heap priority queue (default)
    priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Display and remove elements from the priority queue
    // Elements are returned in descending order (largest first)
    cout << "Priority Queue elements (max-heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // Access the top (largest) element
        pq.pop(); // Remove the top element
    }
    cout << endl;

    // Definition of a min-heap priority queue using greater<int>
    priority_queue<int, vector<int>, greater<int>> min_pq;

    // Inserting elements into the min-heap priority queue
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);

    // Display and remove elements from the min-heap priority queue
    // Elements are returned in ascending order (smallest first)
    cout << "Priority Queue elements (min-heap): ";
    while (!min_pq.empty()) {
        cout << min_pq.top() << " "; // Access the top (smallest) element
        min_pq.pop(); // Remove the top element
    }
    cout << endl;

    return 0;
}