https://leetcode.com/problems/copy-list-with-random-pointer/description/

# LC 138 - Copy List with Random Pointer (Medium)

## Intuition

Each original node must have exactly one corresponding copied node.

The challenge is that a node has two pointers:

- `next`
- `random`

Since `random` can point anywhere (even forward, backward, or `nullptr`), we cannot correctly assign it while creating nodes unless we know where its copied node is.

A **HashMap** solves this by maintaining a mapping:

```cpp
Original Node  --->  Copied Node
```

Once every original node has a corresponding copy, connecting `next` and `random` becomes straightforward.

---

## Approach

Traverse the list once.

For every original node:

1. Create its copied node if it doesn't already exist.
2. Copy the value.
3. Ensure the copied `next` node exists.
4. Connect the copied `next`.
5. Ensure the copied `random` node exists.
6. Connect the copied `random`.

Finally, return the copied head.

---

## Why `unordered_map<Node*, Node*>`?

The key is the **address of the original node**.

```cpp
unordered_map<Node*, Node*> mp;
```

Example:

```text
Original List

A ----> B ----> C
 \       ^
  \------|

HashMap

A -> A'
B -> B'
C -> C'
```

Whenever we need the copy of any original node,

```cpp
mp[original]
```

returns its copied node.

---

## Why store

```cpp
mp[nullptr] = nullptr;
```

This avoids writing special cases.

Instead of checking

```cpp
if(node->next != nullptr)
```

we can simply write

```cpp
copy->next = mp[node->next];
```

If `node->next` is `nullptr`, the map already returns `nullptr`.

---

## Key Observations

- Every original node has exactly one copied node.
- The HashMap maintains the mapping.
- `random` pointers become easy because every referenced node already has (or immediately gets) a copied node.
- No need to worry whether `random` points ahead or behind.

---

## Common Mistakes

❌ Creating multiple copied nodes for the same original node.

❌ Forgetting to copy the `random` pointer.

❌ Forgetting to handle `nullptr`.

❌ Using node values as map keys instead of node addresses (values may repeat).

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Pattern Learned

### HashMap + Pointer Mapping

Whenever a data structure contains arbitrary pointers or references:

- Graph cloning
- Random pointer linked lists
- Tree cloning with extra pointers

Maintain a mapping:

```text
Original Object
        ↓
Copied Object
```

This allows every pointer in the original structure to be redirected to its corresponding copy efficiently.
