https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

# The Painter's Partition Problem-II

Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is -
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35

Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is -
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60

Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ k ≤ 105

## Intuition

We need to divide boards among painters such that the **maximum time taken by any painter is minimized**.

This is a **Binary Search on Answer** problem, similar to Book Allocation.

## Key Insight

- Each painter gets **contiguous boards**
- Minimum possible time = `max(arr)` (one painter must paint the largest board)
- Maximum possible time = `sum(arr)` (one painter paints all boards)

👉 We binary search in this range.

## Approach

1. Edge case:
   - If `k > n` → return `-1`

2. Binary Search:
   - `st = max(arr)`
   - `end = sum(arr)`

3. For each `mid`:
   - Check if it's possible to assign boards such that no painter exceeds `mid` time.
   - If valid → try smaller (`end = mid - 1`)
   - If invalid → increase (`st = mid + 1`)

4. Return minimum valid `mid`.

## Validity Check (Greedy)

- Assign boards sequentially.
- If adding a board exceeds `mid`, assign to next painter.
- Count painters required.

## Complexity

- **Time:** `O(n log(sum))`
- **Space:** `O(1)`

## Code

```cpp
class Solution {
public:
    bool isValid(vector<int> &arr, int n, int k, int maxBoard){
        int painter = 1;
        int board = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] > maxBoard) return false;

            if(board + arr[i] <= maxBoard){
                board += arr[i];
            }
            else{
                painter++;
                board = arr[i];
            }
        }
        return painter <= k;
    }

    int minTime(vector<int>& arr, int k) {
        int n = arr.size();

        if(k > n) return -1;

        int st = 0, end = 0, ans = -1;

        for(int i = 0; i < n; i++){
            end += arr[i];
            st = max(st, arr[i]);
        }

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isValid(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return ans;
    }
};
```
