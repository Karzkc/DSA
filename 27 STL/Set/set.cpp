#include <iostream>
#include <set>

int main()
{
    std::set<int> s;

    // Insert elements
    s.insert(5);
    s.insert(1);
    s.insert(10);
    s.insert(5); // Duplicate, will not be added

    // Iterate and print elements
    std::cout << "Set elements: ";
    for (int x : s)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    int key = 10;
    if (s.find(key) != s.end())
    {
        std::cout << key << " is present in the set." << std::endl;
    }
    else
    {
        std::cout << key << " is not present in the set." << std::endl;
    }

    // Erase an element
    s.erase(1);

    // Print after erasing
    std::cout << "After erasing 1: ";
    for (int x : s)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Lower and upper bound
    std::set<int>::iterator lb = s.lower_bound(5);
    std::set<int>::iterator ub = s.upper_bound(5);

    if (lb != s.end())
        std::cout << "Lower bound of 5: " << *lb << std::endl;
    else
        std::cout << "Lower bound of 5 does not exist." << std::endl;

    if (ub != s.end())
        std::cout << "Upper bound of 5: " << *ub << std::endl;
    else
        std::cout << "Upper bound of 5 does not exist." << std::endl;
    return 0;
}