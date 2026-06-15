https://leetcode.com/problems/two-sum/

# Two Sum

## Intuition

We need to find two indices whose values add up to the target.

Brute force would check every pair:

```text
nums[i] + nums[j]
```

which takes:

```text
O(n²)
```

👉 Instead, store previously seen numbers in a Hash Map and look for the required complement.

---

## Key Insight

For every number:

```cpp
first = nums[i]
```

we need:

```cpp
second = target - first
```

If `second` has already been seen, we found the answer.

---

## Approach

1. Create a Hash Map:

   ```cpp
   value → index
   ```

2. Traverse the array.

3. For every element:
   - Calculate:
     ```cpp
     target - nums[i]
     ```
   - Check if it exists in the map.

4. If found:
   - Return current index and stored index.

5. Otherwise:
   - Store current element in map.

---

## Why Store After Checking?

Wrong:

```cpp
m[nums[i]] = i;

if(m.find(sec) != m.end())
```

This may allow using the same element twice.

Correct:

```cpp
if(m.find(sec) != m.end())
{
    return {i, m[sec]};
}

m[nums[i]] = i;
```

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Code

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {

        int sec = target - nums[i];

        if (m.find(sec) != m.end()) {
            return {i, m[sec]};
        }

        m[nums[i]] = i;
    }

    return {};
}
```

---

## Example

Input:

```cpp
nums = {2,7,11,15}
target = 9
```

### Iteration 1

```cpp
nums[i] = 2
sec = 7
```

Map:

```cpp
{2 : 0}
```

---

### Iteration 2

```cpp
nums[i] = 7
sec = 2
```

Map contains:

```cpp
2
```

Return:

```cpp
{1, 0}
```

---

## Pattern

```text
Hash Map
Complement Lookup
```

---

## Common Mistakes

- Using nested loops `O(n²)` ❌
- Storing current element before checking ❌
- Returning values instead of indices ❌
- Forgetting final return statement ❌

---

## Memory Trick

```text
Current Number

Need:
target - current

Found in map?
→ Return answer

Not found?
→ Store current
```
