https://leetcode.com/problems/sort-colors/description/

# Sort Colors (Dutch National Flag Problem)

- Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
  We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
  You must solve this problem without using the library's sort function.

- Example 1:
  Input: nums = [2,0,2,1,1,0]
  Output: [0,0,1,1,2,2]

- Example 2:
  Input: nums = [2,0,1]
  Output: [0,1,2]

- Constraints:
  n == nums.length
  1 <= n <= 300
  nums[i] is either 0, 1, or 2.

## Intuition

We need to sort an array containing only `0`, `1`, and `2` without using built-in sort.
👉 Since values are limited, we can:

- Count and overwrite (2-pass)
- Or use **Dutch National Flag algorithm (1-pass optimal)**

---

## Key Insight

We divide array into 3 parts:

[0s | 1s | unknown | 2s]
↓ ↓ ↓ ↓
low mid mid high

- **low**: next position for 0
- **mid**: current element being processed
- **high**: next position for 2

Process elements using pointers and place them in correct region.

---

## Approach

### 1️⃣ Brute Force

- Use `sort()` → `O(n log n)`
- ❌ Not allowed in question

---

### 2️⃣ Better (Counting Sort - 2 Pass)

- Count number of `0`, `1`, `2`
- Overwrite array accordingly

👉 Time: `O(n)`  
👉 Space: `O(1)`

---

### 3️⃣ Optimal (Dutch National Flag - 1 Pass)

- Use 3 pointers:
- `low` → next position for `0`
- `mid` → current element
- `high` → next position for `2`

- Traverse while `mid <= high`:
- If `nums[mid] == 0`:
  - swap with `low`, increment both
- If `nums[mid] == 1`:
  - just move `mid`
- If `nums[mid] == 2`:
  - swap with `high`, decrement `high`

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Code

### Counting (2-pass)

```cpp
void sortColors_optimized(vector<int> &nums)
{
  int zero = 0, one = 0, two = 0;

  for (int i : nums)
  {
      if (i == 0) zero++;
      else if (i == 1) one++;
      else two++;
  }

  int idx = 0;

  for (int i = 0; i < zero; i++) nums[idx++] = 0;
  for (int i = 0; i < one; i++) nums[idx++] = 1;
  for (int i = 0; i < two; i++) nums[idx++] = 2;
}
```

### Optimal (Dutch National Flag)

```cpp
void sortColors(vector<int>& nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high--]);
        }
    }
}
```
