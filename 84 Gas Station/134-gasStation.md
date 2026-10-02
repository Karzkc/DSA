https://leetcode.com/problems/gas-station/description/

# LC 134 — Gas Station

## Problem

Find the starting gas station from which you can complete the circular route exactly once. Return `-1` if impossible.

## Intuition

- First check whether **total gas < total cost** → impossible.
- Maintain `currgas` while traversing.
- If `currgas < 0` at station `i`, the current starting point cannot work.
- Start fresh from `i + 1`.

## Approach

1. Calculate total `gasSum` and `costSum`.
2. If `gasSum < costSum`, return `-1`.
3. Traverse again:
   - `currgas += gas[i] - cost[i]`
   - If `currgas < 0`:
     - `start = i + 1`
     - `currgas = 0`

4. Return `start`.

## Key Observation

If starting from `start` causes the tank to become negative at `i`, **every station between `start` and `i` also cannot be a valid starting point**.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Code

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gasSum = 0, costSum = 0;

    for (int i = 0; i < gas.size(); i++) {
        gasSum += gas[i];
        costSum += cost[i];
    }

    if (gasSum < costSum) {
        return -1;
    }

    int start = 0;
    int currgas = 0;

    for (int i = 0; i < gas.size(); i++) {
        currgas += gas[i] - cost[i];

        if (currgas < 0) {
            currgas = 0;
            start = i + 1;
        }
    }

    return start;
}
```
