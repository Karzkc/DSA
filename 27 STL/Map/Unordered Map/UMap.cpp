#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Declaration
    std::unordered_map<std::string, int> umap;

    // Insertion
    umap["apple"] = 2;
    umap["banana"] = 5;
    umap.insert({"orange", 3});

    // Access
    std::cout << "apple: " << umap["apple"] << std::endl;

    // Iteration
    std::cout << "All elements:\n";
    for (const auto& pair : umap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    // Find
    auto it = umap.find("banana");
    if (it != umap.end()) {
        std::cout << "Found banana: " << it->second << std::endl;
    }

    // Erase
    umap.erase("orange");

    // Size
    std::cout << "Size: " << umap.size() << std::endl;

    // Check existence
    if (umap.count("apple")) {
        std::cout << "apple exists\n";
    }

    // Clear
    umap.clear();
    std::cout << "Size after clear: " << umap.size() << std::endl;

    return 0;
}

/*
Unordered Map (std::unordered_map):
- Stores key-value pairs with unique keys.
- Uses hash table for fast average O(1) access, insertion, and deletion.
- Keys are not stored in any particular order.
- Requires #include <unordered_map>
- Common methods: insert, erase, find, count, size, clear, operator[]
*/