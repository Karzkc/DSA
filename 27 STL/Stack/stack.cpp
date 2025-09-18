#include <iostream>
#include <stack> // Include the stack header from STL

int main()
{
    // Create a stack of integers
    std::stack<int> s;

    // Push elements onto the stack
    s.push(10); // Stack: 10
    s.push(20); // Stack: 10, 20
    s.push(30); // Stack: 10, 20, 30

    // Display the top element
    std::cout << "Top element: " << s.top() << std::endl; // 30

    // Pop an element from the stack
    s.pop(); // Removes 30, Stack: 10, 20

    // Display the new top element
    std::cout << "Top element after pop: " << s.top() << std::endl; // 20

    // Check if the stack is empty
    if (s.empty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Display the size of the stack
    std::cout << "Stack size: " << s.size() << std::endl; // 2

    // Serialize: Print and pop all elements
    std::cout << "Serialized stack (top to bottom): ";
    while (!s.empty())
    {
        std::cout << s.top() << " "; // Print top element
        s.pop();                     // Remove top element
    }
    std::cout << std::endl;

    // Demonstrate size after popping all elements
    std::cout << "Stack size after serialization: " << s.size() << std::endl; // 0

    // Demonstrate swap
    std::stack<int> s2;
    s2.push(100);
    s2.push(200);

    // Swap s and s2
    s.swap(s2);

    std::cout << "After swap, top of s: " << (s.empty() ? -1 : s.top()) << std::endl; // 200
    std::cout << "After swap, size of s: " << s.size() << std::endl;                  // 2
    std::cout << "After swap, size of s2: " << s2.size() << std::endl;                // 0
    return 0;
}