https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

# Allocate Minimum Pages

Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.
    All books must be allocated.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 103

## Intuition

We need to distribute books such that the **maximum pages assigned to any student is minimized**.

This is a **Binary Search on Answer** problem:

- Instead of searching the array, we search the **range of possible maximum pages**.

## Key Insight

- Minimum possible answer = `max(arr[i])` (a student must take at least one full book)
- Maximum possible answer = `sum(arr)` (one student takes all books)

👉 We binary search in this range to find the minimum valid maximum.

## Approach

1. Edge case:
   - If `k > n` → return `-1` (not enough books)

2. Binary Search:
   - `st = max(arr)`
   - `end = sum(arr)`

3. For each `mid`:
   - Check if it's possible to allocate books such that no student gets more than `mid` pages.
   - If valid → try smaller (`end = mid - 1`)
   - If not valid → increase (`st = mid + 1`)

4. Return the minimum valid `mid`.

## Validity Check (Greedy)

- Assign books sequentially.
- If adding a book exceeds `mid`, assign to next student.
- Count number of students required.

## Complexity

- **Time:** `O(n log(sum))`
- **Space:** `O(1)`

## Code

```cpp
class Solution {
public:
    bool isValid(vector<int> &arr, int n, int k, int maxPages) {
        int student = 1, pages = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxPages) return false;

            if (pages + arr[i] <= maxPages) {
                pages += arr[i];
            } else {
                student++;
                pages = arr[i];     
            }
        }

        return student <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (k > n) return -1;

        int st = 0, end = 0, ans = -1;

        for (int i = 0; i < n; i++) {
            end += arr[i];
            st = max(st, arr[i]);
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(arr, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};
```
