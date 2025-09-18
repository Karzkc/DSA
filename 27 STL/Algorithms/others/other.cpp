#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric> // for iota, accumulate
#include <bitset>
using namespace std;

int main()
{
    // Example vector
    vector<int> v = {1, 2, 3, 4, 5};

    // 1. reverse
    reverse(v.begin(), v.end());
    cout << "Reverse: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 2. next_permutation
    next_permutation(v.begin(), v.end());
    cout << "Next permutation: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 3. prev_permutation
    prev_permutation(v.begin(), v.end());
    cout << "Prev permutation: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 4. swap
    swap(v[0], v[1]);
    cout << "After swap: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 5. max_element, min_element
    auto max_it = max_element(v.begin(), v.end());
    auto min_it = min_element(v.begin(), v.end());
    cout << "Max element: " << *max_it << ", Min element: " << *min_it << "\n";

    // 6. binary_search (requires sorted vector)
    sort(v.begin(), v.end());
    int key = 3;
    bool found = binary_search(v.begin(), v.end(), key);
    cout << "Binary search for " << key << ": " << (found ? "Found" : "Not found") << "\n";

    // 7. count
    int cnt = count(v.begin(), v.end(), 3);
    cout << "Count of 3: " << cnt << "\n";

    // 8. count set bits (builtin_popcount)
    int num = 29; // 11101
    cout << "Set bits in " << num << ": " << __builtin_popcount(num) << "\n";
    cout << "Set bits in " << num << " (ll): " << __builtin_popcountll((long long)num) << "\n";

    // 9. accumulate (sum)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << "\n";

    // 10. fill
    fill(v.begin(), v.end(), 7);
    cout << "After fill: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // 11. unique (remove duplicates, needs sorted vector)
    vector<int> dup = {1, 2, 2, 3, 3, 3, 4};
    auto it = unique(dup.begin(), dup.end());
    dup.erase(it, dup.end());
    cout << "After unique: ";
    for (int x : dup)
        cout << x << " ";
    cout << "\n";

    // 12. lower_bound, upper_bound
    vector<int> sorted = {1, 2, 2, 3, 4, 5};
    auto lb = lower_bound(sorted.begin(), sorted.end(), 2);
    auto ub = upper_bound(sorted.begin(), sorted.end(), 2);
    cout << "Lower bound of 2: " << (lb - sorted.begin()) << ", Upper bound: " << (ub - sorted.begin()) << "\n";

    // 13. sort (descending)
    sort(sorted.begin(), sorted.end(), greater<int>());
    cout << "Sorted descending: ";
    for (int x : sorted)
        cout << x << " ";
    cout << "\n";

    // 14. rotate
    rotate(sorted.begin(), sorted.begin() + 2, sorted.end());
    cout << "After rotate: ";
    for (int x : sorted)
        cout << x << " ";
    cout << "\n";

    // 15. partition
    vector<int> part = {1, 2, 3, 4, 5, 6};
    partition(part.begin(), part.end(), [](int x)
              { return x % 2 == 0; });
    cout << "Partition (evens first): ";
    for (int x : part)
        cout << x << " ";
    cout << "\n";

    // 16. all_of, any_of, none_of
    cout << "All even: " << all_of(part.begin(), part.end(), [](int x)
                                   { return x % 2 == 0; })
         << "\n";
    cout << "Any even: " << any_of(part.begin(), part.end(), [](int x)
                                   { return x % 2 == 0; })
         << "\n";
    cout << "None even: " << none_of(part.begin(), part.end(), [](int x)
                                     { return x % 2 == 0; })
         << "\n";

    // 17. find
    auto f = find(part.begin(), part.end(), 4);
    cout << "Find 4: " << (f != part.end() ? "Found" : "Not found") << "\n";

    // 18. iota
    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 10);
    cout << "Iota: ";
    for (int x : seq)
        cout << x << " ";
    cout << "\n";

    return 0;
}