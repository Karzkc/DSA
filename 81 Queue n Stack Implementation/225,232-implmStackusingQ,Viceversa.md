https://leetcode.com/problems/implement-stack-using-queues/description/
https://leetcode.com/problems/implement-queue-using-stacks/

# LC 232 + LC 225 — Queue using Stacks & Stack using Queues

Both problems use the same basic trick:

> Make the available data structure behave like the required one by rearranging elements during `push()`.

---

# LC 232 — Implement Queue using Stacks

### Required

Queue = **FIFO**

```text
push → 1 2 3
pop  → 1
```

Using two stacks:

```text
s1 = actual queue
s2 = temporary stack
```

### Push

Move everything from `s1` to `s2`:

```text
s1: 3 2 1
s2: 1 2 3
```

Push the new element into `s1`:

```text
s1: 4
```

Move everything back:

```text
s1: 3 2 1 4
```

Now the **top of `s1` is always the oldest element**.

Therefore:

```cpp
pop()  → s1.top()
peek() → s1.top()
```

### Complexity

- `push()` → `O(n)`
- `pop()` → `O(1)`
- `peek()` → `O(1)`
- `empty()` → `O(1)`
- Space → `O(n)`

---

# LC 225 — Implement Stack using Queues

### Required

Stack = **LIFO**

```text
push → 1 2 3
pop  → 3
```

Using two queues:

```text
q1 = actual stack
q2 = temporary queue
```

### Push

Move everything from `q1` to `q2`:

```text
q1: 1 2 3
q2: 2 3
```

Add the new element to `q1`:

```text
q1: 4
```

Move everything back:

```text
q1: 4 1 2 3
```

Now the **front of `q1` is always the most recently pushed element**.

Therefore:

```cpp
pop() → q1.front()
top() → q1.front()
```

### Complexity

- `push()` → `O(n)`
- `pop()` → `O(1)`
- `top()` → `O(1)`
- `empty()` → `O(1)`
- Space → `O(n)`

---

# Common Pattern

Both solutions deliberately make one operation expensive so that the important operations become simple.

```text
Queue using Stacks:

expensive push
      ↓
top = oldest
      ↓
O(1) pop / peek
```

```text
Stack using Queues:

expensive push
      ↓
front = newest
      ↓
O(1) pop / top
```

### Key takeaway

You **don't have to make every operation O(1)**.

You can rearrange elements during one operation so that the required behavior becomes natural for the remaining operations.
