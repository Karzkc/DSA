https://leetcode.com/problems/first-unique-character-in-a-string/

# LC 387 - First Unique Character in a String

## Intuition

We need to find the **first character that appears exactly once**.

Use two data structures:

```text
HashMap → frequency of each character
Queue   → order of characters that appeared once
```

The queue helps us maintain the **first unique character** without repeatedly scanning the string.

---

## Approach

Traverse the string from left to right.

For every character:

### 1. First occurrence

If the character isn't in the map:

```cpp
if (m.find(s[i]) == m.end())
    q.push(i);
```

Store its index in the queue.

### 2. Update frequency

```cpp
m[s[i]]++;
```

### 3. Remove characters that are no longer unique

The front of the queue may now have frequency > 1.

Keep removing it:

```cpp
while (!q.empty() && m[s[q.front()]] > 1)
    q.pop();
```

After this, the queue front is always the **first unique character so far**.

---

## Why Store Indices?

Instead of storing characters:

```cpp
queue<int> q;
```

we store their indices.

This lets us directly access:

```cpp
s[q.front()]
```

and check its frequency using the map.

---

## Example

```text
s = "leetcode"
```

As we process:

```text
l → queue: [l]
e → queue: [l,e]
e → e is repeated → remove e
t → queue: [l,t]
```

The front remains:

```text
l
```

Therefore the answer is index `0`.

---

## Important Pattern

The key idea is:

```text
HashMap
frequency
   +
Queue
original order
   ↓
First unique element
```

The HashMap answers:

> How many times has this character appeared?

The Queue answers:

> Which candidate appeared first?

---

## Common Mistakes

- Returning the character instead of its index.
- Forgetting to remove repeated characters from the queue.
- Checking only the final frequency without preserving original order.
- Storing characters when indices make the ordering easier to maintain.

---

## Complexity

Let `n = s.length()`.

- **Time:** `O(n)`
- **Space:** `O(n)`

Each index is pushed into and popped from the queue at most once.

---

## Code

```cpp
int firstUniqChar(string s) {
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < s.size(); i++) {

        if (m.find(s[i]) == m.end()) {
            q.push(i);
        }

        m[s[i]]++;

        while (!q.empty() && m[s[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}
```

### Pattern to remember

> **Frequency Map + Queue = first element satisfying a frequency condition while preserving order.**
