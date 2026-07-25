    # LC 141 & LC 142 - Linked List Cycle

## Intuition

Use two pointers:

- Slow → moves 1 step
- Fast → moves 2 steps

If there is a cycle, the fast pointer will eventually catch the slow pointer.

If there is no cycle, fast reaches `nullptr`.

---

## LC 141

Goal:

Return whether a cycle exists.

If:

```cpp
slow == fast
```

there is a cycle.

Otherwise return `false`.

---

## LC 142

Goal:

Return the node where the cycle begins.

After slow and fast meet:

```cpp
slow = head;
```

Now move both pointers one step at a time.

The node where they meet again is the **start of the cycle**.

---

## Why does this work?

Suppose:

```text
x = distance from Head to Cycle Start

d = cycle length

y = distance from Cycle Start to Meeting Point
```

When they meet:

Slow travels

```text
x + y
```

Fast travels

```text
x + y + k × d
```

where `k ≥ 1`.

Since fast moves twice as fast:

```text
2(x+y)=x+y+kd
```

Therefore,

```text
x = kd - y
```

which means

```text
x = (k-1)d + (d-y)
```

Interpretation:

From the meeting point,

- travel the remaining cycle

```text
d-y
```

then

- complete

```text
k-1
```

extra full circles,

and you'll arrive at the cycle start.

Meanwhile, another pointer starting from the head also needs exactly `x` steps.

Hence both pointers meet at the cycle's starting node.

---

## Remove Cycle

After finding the cycle start:

Traverse the cycle until

```cpp
temp->next == start
```

Then:

```cpp
temp->next = nullptr;
```

The cycle is removed.

---

## Common Mistakes

❌ Forgetting

```cpp
slow = head;
```

before finding the cycle start.

---

❌ Using

```cpp
while(slow != fast)
```

immediately after detecting the meeting point.

They are already equal.

---

❌ Forgetting to check

```cpp
fast && fast->next
```

---

## Complexity

- Time: **O(n)**
- Space: **O(1)**

---

## Pattern

Whenever a linked list asks for:

- Detect cycle
- Find cycle start
- Happy Number

Think:

> **Floyd's Slow & Fast Pointer Algorithm**
