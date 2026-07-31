https://leetcode.com/problems/swap-nodes-in-pairs/description/

# LC 24 - Swap Nodes in Pairs

## Intuition

Process the linked list in **groups of 2**.

For every pair:

```text
first → second
```

swap them into

```text
second → first
```

Then connect the previous swapped pair to the current swapped pair.

---

## Approach

For every pair:

1. Store the third node.
2. Reverse the current pair.
3. Connect the previous pair.
4. Move pointers to the next pair.

Repeat until fewer than 2 nodes remain.

---

## Visualization

Before

```text
1 → 2 → 3 → 4
```

Swap first pair

```text
2 → 1    3 → 4
```

Swap second pair

```text
2 → 1 → 4 → 3
```

---

## Pointer Roles

```cpp
first  -> First node of current pair
second -> Second node of current pair
third  -> First node of next pair
curr   -> Tail of previous swapped pair
```

Example:

```text
curr

↓

2 → 1     3 → 4
          ↑   ↑
       first second
```

---

## Swapping

Original

```text
first → second → third
```

After

```text
second → first → third
```

Operations:

```cpp
second->next = first;
first->next = third;
```

---

## Connecting Previous Pair

If this isn't the first pair:

```cpp
curr->next = second;
```

Otherwise,

update the head:

```cpp
head = second;
```

---

## Key Observations

- Save the third node before changing pointers.
- The original first node becomes the tail after swapping.
- `curr` always points to the tail of the previously swapped pair.
- The last single node (if any) remains unchanged.

---

## Common Mistakes

❌ Forgetting to update `head` after the first swap.

❌ Losing the third node before reversing.

❌ Forgetting to reconnect the previous pair.

❌ Trying to swap when fewer than two nodes remain.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Pattern Learned

### Fixed-Size Group Manipulation

Process the linked list in groups of fixed size.

General steps:

1. Save next group's start.
2. Modify current group.
3. Connect previous group.
4. Move to next group.

This idea extends to problems like:

- LC 25 - Reverse Nodes in k-Group
- Reverse every alternate k nodes
- Pair-wise linked list transformations
