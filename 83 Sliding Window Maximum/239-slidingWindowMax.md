https://leetcode.com/problems/sliding-window-maximum/description/

# LC 239 — Sliding Window Maximum

## Problem

Given an array `nums` and window size `k`, return the maximum element in every sliding window.

Example:

```text
nums = [1,3,-1,-3,5,3,6,7], k = 3

Windows:
[1,3,-1] → 3
[3,-1,-3] → 3
[-1,-3,5] → 5
[-3,5,3] → 5
[5,3,6] → 6
[3,6,7] → 7
```

## Intuition — Monotonic Deque

We maintain a **decreasing deque of indices**.

```text
front → largest ... smallest ← back
```

The front always contains the index of the **maximum element** in the current window.

### Why remove from back?

Suppose:

```text
deque: [5, 3]
new element = 6
```

`5` and `3` can never be the maximum while `6` is in the window, so remove them.

```text
deque → [6]
```

### Why store indices instead of values?

We need to know whether an element has **left the window**.

For current index `i`, an index is outside when:

```cpp
index <= i - k
```

---

## Approach

For every index `i`:

### 1. Remove expired indices

```cpp
while (!dq.empty() && dq.front() <= i - k)
    dq.pop_front();
```

These elements are no longer inside the current window.

### 2. Maintain decreasing order

```cpp
while (!dq.empty() && nums[dq.back()] <= nums[i])
    dq.pop_back();
```

Remove elements smaller than or equal to the current element.

### 3. Add current index

```cpp
dq.push_back(i);
```

### 4. Once the first window is complete

```cpp
if (i >= k - 1)
    ans.push_back(nums[dq.front()]);
```

Since the deque is decreasing, `dq.front()` is always the maximum.

---

## Code

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++) {

        // Remove elements outside the window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Window is complete
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

    return ans;
}
```

## Key Observation

The deque is **monotonic decreasing**:

```text
nums[dq.front()] >= nums[dq[1]] >= nums[dq[2]] ...
```

Therefore:

```cpp
nums[dq.front()]
```

is always the window maximum.

## Why `O(n)`?

Although there are `while` loops, each index:

- enters the deque **once**
- can be removed from the front **once**
- can be removed from the back **once**

So total operations are linear.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(k)`

## Common Mistakes

- ❌ Store values instead of indices → can't efficiently detect expired elements.
- ❌ Forget to remove expired front indices.
- ❌ Maintain increasing instead of decreasing order.
- ❌ Add answers before the first complete window.
- ❌ Use `i-k` incorrectly; expired condition is:

```cpp
dq.front() <= i - k
```

**Pattern to remember:**
`Sliding Window Maximum → Monotonic Deque → decreasing → front = maximum`.
