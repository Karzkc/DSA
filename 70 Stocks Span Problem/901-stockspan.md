# LC 901 - Online Stock Span

## Intuition

For each day's price, find how many **consecutive previous days** had a price `<=` today's price.

Example:

```text
Prices: 100 80 60 70 60 75 85
Span:     1  1  1  2  1  4  6
```

Use a **monotonic decreasing stack**.

But since prices arrive **one at a time**, we cannot use an array of all prices.

So store:

```text
(price, span)
```

Each pair summarizes how many previous days that price already covers.

---

## Approach

For every `next(price)`:

1. Start with:

   ```cpp
   span = 1;
   ```

   Today's price always counts.

2. While the stack top has a price `<=` today's price:
   - Add its stored span.
   - Remove it.

3. Push:

   ```cpp
   {price, span}
   ```

4. Return `span`.

---

## Why Store the Span?

Example:

```text
Stack:

(100,1)
(80,1)
(70,2)
```

New price:

```text
75
```

`70 <= 75`, so pop it:

```text
span = 1 + 2 = 3
```

The stored `2` already represents the days covered by `70`.

Now `80 > 75`, so stop.

Push:

```text
(75,3)
```

No need to individually count those previous days again.

---

## Key Idea

The stack is **monotonically decreasing by price**.

```text
100
 80
 75
```

When a new price arrives, smaller/equal prices are removed because the new price can now cover their entire spans.

---

## Common Mistakes

- Storing only prices instead of `(price, span)`.
- Forgetting to add the popped element's **span**.
- Using `<` instead of `<=`.
- Creating the stack inside `next()` instead of making it a class member.
- Forgetting that each new price contributes `1` to its own span.

---

## Complexity

Although one `next()` call can pop many elements:

- Each element is pushed **once**.
- Each element is popped **once**.

Therefore:

- **Total Time:** `O(n)`
- **Amortized Time per call:** `O(1)`
- **Space:** `O(n)`

---

## Pattern Learned

### Monotonic Stack + Compressed Information

Instead of storing every previous element separately, store:

```text
value + information about the range it represents
```

This lets future elements skip over entire groups efficiently.

---

## Memory Trick

```text
New price
    ↓
Pop smaller/equal prices
    ↓
Add their spans
    ↓
Push {price, total span}
```

Think:

> **Pop → Add Span → Push**
