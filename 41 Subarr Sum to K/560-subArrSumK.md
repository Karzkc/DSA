https://leetcode.com/problems/subarray-sum-equals-k/description/

# Subarray Sum Equals K

## Intuition

We need to count the number of subarrays whose sum equals `k`.

Brute force would generate every possible subarray:

```text
O(n²)
```

This is too slow for large inputs.

👉 Use Prefix Sum + Hash Map.

---

## Key Insight

Let:

```cpp
prefix[i]
```

represent the sum of elements from:

```text
0 → i
```

Suppose current prefix sum is:

```cpp
prefix
```

and we need a subarray sum equal to:

```cpp
k
```

Then:

```text
prefix - previousPrefix = k
```

Rearranging:

```text
previousPrefix = prefix - k
```

So if we've previously seen:

```cpp
prefix - k
```

then a valid subarray exists.

---

## Example

```cpp
nums = [1,1,1]
k = 2
```

Prefix sums:

```text
1, 2, 3
```

At:

```text
prefix = 3
```

Need:

```text
3 - 2 = 1
```

Since prefix sum `1` was seen before:

```text
Subarray Sum = 2
```

Count it.

---

## Why Do We Initialize?

```cpp
mp[0] = 1;
```

This handles cases where:

```text
prefix sum itself equals k
```

Example:

```cpp
nums = [3]
k = 3
```

Current prefix:

```text
3
```

Need:

```text
3 - 3 = 0
```

Since:

```cpp
mp[0] = 1
```

we correctly count this subarray.

---

## Approach

1. Create a hash map:

```cpp
prefixSum → frequency
```

2. Initialize:

```cpp
mp[0] = 1
```

3. Traverse the array.

4. Update running prefix sum.

5. Check if:

```cpp
prefix - k
```

exists in the map.

6. Add its frequency to answer.

7. Store current prefix sum in map.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Code

```cpp
int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> mp;

    mp[0] = 1;

    int prefix = 0;
    int count = 0;

    for (int num : nums) {

        prefix += num;

        count += mp[prefix - k];

        mp[prefix]++;
    }

    return count;
}
```

---

## Dry Run

Input:

```cpp
nums = [1,1,1]
k = 2
```

Initial:

```cpp
mp = {0 : 1}
prefix = 0
count = 0
```

### First Element

```cpp
prefix = 1
```

Need:

```cpp
1 - 2 = -1
```

Not found.

Store:

```cpp
mp[1]++
```

---

### Second Element

```cpp
prefix = 2
```

Need:

```cpp
2 - 2 = 0
```

Found once.

```cpp
count = 1
```

Store:

```cpp
mp[2]++
```

---

### Third Element

```cpp
prefix = 3
```

Need:

```cpp
3 - 2 = 1
```

Found once.

```cpp
count = 2
```

Answer:

```text
2
```

---

## Pattern

```text
Prefix Sum
+
Hash Map
```

---

## Common Mistakes

- Using sliding window ❌

  (Array contains negative numbers, so sliding window doesn't work.)

- Forgetting:

  ```cpp
  mp[0] = 1;
  ```

- Using nested loops `O(n²)` ❌

- Storing only existence instead of frequency ❌

  Multiple identical prefix sums can occur.

---

## Memory Trick

```text
Current Prefix = P

Need:
P - K

If (P-K) existed before,
a valid subarray ends here.
```
