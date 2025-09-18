#include <iostream>
#include <vector>
#include <algorithm>

// Custom comparator as a functor
struct CustomComparator {
    bool operator()(int a, int b) const {
        // Example: sort in descending order
        return a > b;
    }
};

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 3};

    // Sort using custom comparator functor
    std::sort(vec.begin(), vec.end(), CustomComparator());

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}