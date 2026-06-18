# 3Sum
https://leetcode.com/problems/3sum/
## Intuition

We need to find all unique triplets such that:

```text
nums[i] + nums[j] + nums[k] = 0
```

Brute force would check every possible triplet:

```text
O(n³)
```

which is too slow.

👉 Sort the array and use the Two Pointer technique.

---

## Key Insight

After sorting:

```text
If sum is too small → move left pointer right
If sum is too large → move right pointer left
```

This allows us to find pairs efficiently.

---

## Approach

### 1. Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Sorting enables the two-pointer technique.

---

### 2. Fix First Element

Use:

```cpp
nums[i]
```

as the first element of the triplet.

Skip duplicates:

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

---

### 3. Find Remaining Two Numbers

Initialize:

```cpp
j = i + 1
k = n - 1
```

Calculate:

```cpp
sum = nums[i] + nums[j] + nums[k];
```

---

### 4. Move Pointers

If:

```text
sum < 0
```

increase sum:

```cpp
j++;
```

If:

```text
sum > 0
```

decrease sum:

```cpp
k--;
```

If:

```text
sum == 0
```

store triplet and move both pointers.

---

### 5. Skip Duplicates

After finding a valid triplet:

```cpp
while (j < k && nums[j] == nums[j - 1])
    j++;
while (j < k && nums[k] == nums[k + 1]) 
    k--;
```

This prevents duplicate triplets.

---

## Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)` (excluding answer array)

---

## Code

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k) {

            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {

                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1]){
                    k--;
            }
            }
        }
    }

    return ans;
}
```

---

## Example

Input:

```text
[-1,0,1,2,-1,-4]
```

Sorted:

```text
[-4,-1,-1,0,1,2]
```

Triplets:

```text
[-1,-1,2]
[-1,0,1]
```

---

## Pattern

```text
Sorting + Two Pointers
```

---

## Common Mistakes

- Using brute force `O(n³)` ❌
- Forgetting to sort the array ❌
- Not skipping duplicate `i` values ❌
- Not skipping duplicate pointer values ❌
- Using a set unnecessarily ❌

---

## Memory Trick

```text
Fix one number

Use two pointers
to find remaining two

Too small → Left++
Too large → Right--
Equal → Store answer
```
