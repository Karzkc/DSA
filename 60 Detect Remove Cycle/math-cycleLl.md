### Understanding the math (simple)

Let's use your variables.

```
Head
 |
 |<----- x ----->|
 v               v
1 → 2 → 3 → 4 → 5 → 6
          ↑         |
          |_________|
```

Suppose they meet here:

```
Head
 |
 |<---- x ----->|
 v              v
1 → 2 → 3 → 4 → 5 → 6
              ↑   S/F
              |____|
```

Let

- `x` = Head → Cycle Start
- `y` = Cycle Start → Meeting Point
- `d` = Cycle Length

Slow walks

```
x + y
```

Fast walks

```
x + y + d
```

(assume it completed one extra loop)

Since fast is twice as fast:

```
2(x+y)=x+y+d
```

```
x+y=d
```

```
x=d-y
```

Meaning:

- One pointer at **Head** needs `x` steps to reach the cycle start.
- One pointer at the **Meeting Point** needs `d-y` steps to finish the current loop and reach the cycle start.

Since `x = d - y` (or more generally `x = (k-1)d + (d-y)`), both pointers take the same number of steps.

That's why resetting one pointer to the head and moving both one step at a time makes them meet **exactly at the start of the cycle**.

This is the key idea to remember; you don't need to memorize the derivation beyond `2(x+y)=x+y+kd`.
