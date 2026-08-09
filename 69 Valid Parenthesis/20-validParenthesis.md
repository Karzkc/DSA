# LC 20 - Valid Parentheses

## Intuition

Whenever an opening bracket appears,

store it because it must be matched later.

Whenever a closing bracket appears,

it must match the **most recent unmatched opening bracket**.

This is exactly what a **Stack (LIFO)** provides.

---

## Approach

Traverse the string from left to right.

- If the character is an opening bracket, push it onto the stack.
- If it is a closing bracket:
  - If the stack is empty, return `false`.
  - Otherwise, check whether it matches the stack's top.
  - If it matches, pop it.
  - Otherwise, return `false`.

At the end, the stack must be empty.

---

## Example

Input

```text
({[]})
```

Stack:

```text
(

( {

( { [

( {

(

empty
```

Valid.

---

Invalid Example

```text
([)]
```

Stack:

```text
(

( [

Current = )

Top = [

Mismatch

Return false
```

---

## Why Stack?

The last opening bracket must always be closed first.

Example:

```text
({[]})
```

The order of closing is:

```text
]

}

)
```

which is exactly **Last In, First Out (LIFO)**.

---

## Key Observations

- Every closing bracket must have a matching opening bracket.
- The most recent opening bracket must be closed first.
- If the stack becomes empty before finding a match, the string is invalid.
- After processing the entire string, the stack should be empty.

---

## Common Mistakes

❌ Forgetting to check whether the stack is empty before accessing `top()`.

❌ Forgetting to pop after a successful match.

❌ Returning `true` without checking whether the stack is empty.

❌ Comparing the wrong bracket pair.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Pattern Learned

### Stack + Matching Pairs

Whenever the problem involves:

- Matching brackets
- Nested structures
- Undoing the most recent operation

Think:

> **Stack (LIFO)**

This same pattern appears in:

- Valid Parentheses
- Longest Valid Parentheses
- Basic Calculator
- Decode String
- Min Stack
