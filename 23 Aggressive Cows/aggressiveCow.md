https://www.geeksforgeeks.org/problems/aggressive-cows/1

# Aggressive Cows

You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.

Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.

Constraints:
2 ≤ stalls.size() ≤ 106
0 ≤ stalls[i] ≤ 108
2 ≤ k ≤ stalls.size()


## Intuition
We need to place `k` cows in stalls such that the **minimum distance between any two cows is maximized**.

👉 This is the **opposite of Book Allocation / Painter Partition**:
- There → minimize maximum
- Here → maximize minimum

## Key Insight
- Larger minimum distance = harder to place cows
- Smaller minimum distance = easier to place cows

👉 So we use **Binary Search on Answer** to find the maximum valid minimum distance.

## Approach
1. Sort the stalls (important for distance calculation)

2. Binary Search:
   - `st = 0`
   - `end = max(stalls) - min(stalls)`

3. For each `mid` (minimum distance):
   - Check if we can place all cows with at least `mid` distance
   - If valid → try larger distance (`st = mid + 1`)
   - If invalid → reduce distance (`end = mid - 1`)

4. Return maximum valid `mid`

## Validity Check (Greedy)
- Place first cow at first stall
- Place next cow only if distance ≥ `mid`
- Count cows placed
- If cows ≥ k → valid

## Complexity
- **Time:** `O(n log(maxDistance))`
- **Space:** `O(1)`

## Code
```cpp
class Solution {
public:
    bool isValid(vector<int> &arr, int n, int k, int minStalls){
        int cows = 1;
        int lastPos = arr[0];
        
        for(int i = 1; i < n; i++){
            if(arr[i] - lastPos >= minStalls){
                cows++;
                lastPos = arr[i];
            }
            if(cows == k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int st = 0;
        int end = stalls[n - 1] - stalls[0];
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isValid(stalls, n, k, mid)){
                ans = mid;
                st = mid + 1;   // move right (maximize)
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
};
```