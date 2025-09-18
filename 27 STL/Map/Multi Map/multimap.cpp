#include <iostream>
#include <map>

int main() {
    // Declare a multimap of int and string
    std::multimap<int, std::string> mm;

    // Insert elements (duplicate keys allowed)
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Apricot"});
    mm.insert({3, "Cherry"});
    mm.insert({2, "Blueberry"});

    // Iterate and print all elements
    std::cout << "All elements in multimap:\n";
    for (const auto& pair : mm) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }

    // Find all values for a specific key
    int key = 2;
    std::cout << "\nValues for key " << key << ":\n";
    auto range = mm.equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << '\n';
    }

    return 0;
}