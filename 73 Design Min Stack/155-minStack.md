https://leetcode.com/problems/min-stack/description/

# LC 155 - Min Stack

## Intuition

A normal stack can give:

- `push()` → O(1)
- `pop()` → O(1)
- `top()` → O(1)

But `getMin()` would normally require scanning the entire stack → `O(n)`.

We need to remember the minimum **at every level of the stack**.

---

# Approach 1 - Store `(value, minimum_so_far)`

Each element stores:

```text
(value, minimum among all elements up to here)
```

Example:

```text
push 5 → (5,5)
push 3 → (3,3)
push 7 → (7,3)
push 2 → (2,2)
```

So:

```cpp
getMin() = s.top().second;
```

### Logic

```cpp
int minVal = s.empty()
           ? value
           : min(value, s.top().second);
```

Then push:

```cpp
s.push({value, minVal});
```

### Complexity

- `push` → O(1)
- `pop` → O(1)
- `top` → O(1)
- `getMin` → O(1)
- Space → O(n)

### Recommended approach

This is the **cleanest and easiest to explain** solution.

---

# Approach 2 - Encode the Minimum

Instead of storing the minimum with every element, maintain one separate:

```cpp
minVal
```

When a new value becomes the minimum, store a special encoded value:

```cpp
2 * value - minVal
```

Then update:

```cpp
minVal = value;
```

The encoded value acts as a marker telling us:

> "The minimum changed at this point."

---

## Detecting an Encoded Value

If:

```cpp
s.top() < minVal
```

then the top value is encoded.

The actual top value is:

```cpp
minVal
```

When popping an encoded value, recover the previous minimum:

```cpp
minVal = 2 * minVal - s.top();
```

---

## Why Encoding Works

Suppose:

```text
old minimum = 5
new value   = 3
```

Store:

```text
2 × 3 - 5 = 1
```

Now:

```text
stored value = 1
minVal = 3
```

Since:

```text
1 < 3
```

we know the value is encoded.

From it we can recover the old minimum:

```text
2 × 3 - 1 = 5
```

---

## Complexity

- `push` → O(1)
- `pop` → O(1)
- `top` → O(1)
- `getMin` → O(1)
- Space → O(n)

The stack still contains `n` elements, so this does **not** change the overall asymptotic space complexity.

---

# Comparison

|                          | Pair Approach       | Encoding Approach   |
| ------------------------ | ------------------- | ------------------- |
| Time                     | O(1) all operations | O(1) all operations |
| Space                    | O(n)                | O(n)                |
| Difficulty               | Easy                | More tricky         |
| Overflow concerns        | No                  | Yes                 |
| Readability              | Excellent           | Lower               |
| Interview recommendation | ⭐⭐⭐⭐⭐          | ⭐⭐⭐              |

---

## Key Pattern

### Minimum-so-far

The main idea behind the pair approach is:

```text
Current Value
+
Minimum Seen So Far
```

This avoids repeatedly searching the stack for the minimum.

---

## Common Mistakes

### Pair approach

- Forgetting to update the minimum when pushing.
- Using the current value instead of `min(value, previousMin)`.

### Encoding approach

- Forgetting to use a wider integer type.
- Incorrectly detecting encoded values.
- Forgetting to restore the previous minimum during `pop()`.
- Integer overflow when calculating:

```cpp
2 * value - minVal
```

---

## Final Takeaway

For practical coding and interviews:

> **Use the pair approach.**

The encoding approach is useful to understand because it demonstrates how information can be compressed into the stack itself, but the pair solution is simpler, clearer, and already optimal in time complexity.
