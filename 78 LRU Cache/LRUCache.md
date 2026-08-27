https://leetcode.com/problems/lru-cache/description/

# LC 146 - LRU Cache

## Intuition

We need two things:

1. Find a key quickly → **HashMap**
2. Know which key was used least recently → **Doubly Linked List**

So combine:

```text
HashMap
key → Node*

        +

Doubly Linked List
head → Most Recently Used → ... → Least Recently Used → tail
```

Both operations can then be `O(1)`.

---

## Doubly Linked List

Use two dummy nodes:

```text
head ⇄ Node ⇄ Node ⇄ Node ⇄ tail
```

- Near `head` = Most Recently Used
- Near `tail` = Least Recently Used

### `addNode()`

Always insert a node immediately after `head`.

```text
head → newNode → oldFirst
```

### `delNode()`

Only **unlink** the node:

```cpp
oldNode->prev->next = oldNode->next;
oldNode->next->prev = oldNode->prev;
```

Important:

> `delNode()` should NOT delete the node.

We may remove a node temporarily and put the **same node back at the front** during `get()`.

---

## `get(key)`

If key doesn't exist:

```cpp
return -1;
```

Otherwise:

1. Get the node from the map.
2. Remove it from its current position.
3. Add it to the front because it was just used.
4. Return its value.

```text
Before:

head → A → B → C → tail
       ↑
      get(A)

After:

head → A → B → C → tail
       ↑
    moved to front
```

The map still points to the same node.

---

## `put(key, value)`

### If key already exists

Remove the old node and erase its map entry.

Then create/add the new node at the front.

### If cache is full

The node immediately before `tail` is the **Least Recently Used** node.

```cpp
Node* lru = tail->prev;
```

Remove it from:

- Linked list
- HashMap

Then insert the new node at the front.

---

## Why HashMap + Doubly Linked List?

### HashMap alone

Can find a key in `O(1)`.

But cannot efficiently determine the LRU node.

### Linked List alone

Can maintain order efficiently.

But finding a key takes `O(n)`.

### Together

```text
HashMap → Find node in O(1)

DLL → Move/remove node in O(1)
```

Therefore:

```text
get() → O(1)
put() → O(1)
```

---

## Key Insight

The HashMap stores:

```cpp
unordered_map<int, Node*> m;
```

So it doesn't store the value directly.

It stores a **pointer to the actual node** in the linked list.

```text
key 5
  ↓
HashMap
  ↓
Node(5, 100)
  ↓
prev / next
```

This lets us move the node around without searching for it.

---

## Common Mistake

### Don't `delete` inside `delNode()`

Wrong:

```cpp
void delNode(Node* node) {
    ...
    delete node;
}
```

Because `get()` needs to reuse the node:

```cpp
delNode(node);
addNode(node);
```

`delNode()` should only unlink.

When a node is **actually discarded** because of capacity, then it can be deleted.

---

## Example

Capacity = `2`

```text
put(1,10)
put(2,20)
```

```text
head → 2 → 1 → tail
```

`2` is most recently used.

Now:

```text
get(1)
```

Move `1` to front:

```text
head → 1 → 2 → tail
```

Now:

```text
put(3,30)
```

Cache is full.

`2` is the LRU node, so remove it:

```text
head → 3 → 1 → tail
```

---

## Complexity

- `get()` → **O(1)**
- `put()` → **O(1)**
- Space → **O(capacity)**

---

## Pattern Learned

### HashMap + Doubly Linked List

Use this combination when you need:

> **Fast lookup + fast ordering/reordering**

Classic example:

```text
LRU Cache
```

The core idea:

```text
HashMap → where is the node?
DLL     → what is its usage order?
```
