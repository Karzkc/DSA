# Recursion

## What is Recursion?

Recursion is a programming technique where a function calls itself to solve a problem by breaking it into smaller subproblems.

Instead of solving the entire problem at once:

```text
Big Problem
    ↓
Smaller Problem
    ↓
Even Smaller Problem
    ↓
Base Case
```

The recursive calls continue until a stopping condition is reached.

---

## Structure of a Recursive Function

Every recursive function must contain:

### 1. Base Case

The condition that stops further recursive calls.

Without a base case:

```text
Infinite Recursive Calls
→ Stack Overflow
→ Program Crash
```

### 2. Recursive Call

The function calls itself with a smaller version of the original problem.

General Structure:

```cpp
returnType function(parameters)
{
    // Base Case
    if(condition)
    {
        return value;
    }

    // Recursive Call
    return function(smaller_problem);
}
```

---

## How Recursion Works

Example:

```cpp
void printNum(int n)
{
    if(n == 0)
        return;

    cout << n << " ";

    printNum(n - 1);
}
```

Calling:

```cpp
printNum(3);
```

Execution:

```text
printNum(3)
    ↓
printNum(2)
    ↓
printNum(1)
    ↓
printNum(0)
```

Then functions return one by one.

---

# Call Stack

Every function call is stored in memory inside the Call Stack.

Example:

```cpp
printNum(3);
```

Stack Growth:

```text
printNum(3)
printNum(2)
printNum(1)
printNum(0)
```

When the base case is reached:

```text
printNum(0) returns
printNum(1) returns
printNum(2) returns
printNum(3) returns
```

This process is called:

```text
Stack Unwinding
```

---

# Recursion Tree

A recursion tree visually represents all recursive calls.

Example:

```cpp
fun(3)
```

Tree:

```text
fun(3)
  |
fun(2)
  |
fun(1)
  |
fun(0)
```

For more complex recursive problems, recursion trees help in:

- Understanding execution
- Counting recursive calls
- Calculating complexity

---

# Mathematics of Recursion

Recursive algorithms are often represented using a:

```text
Recurrence Relation
```

A recurrence relation expresses a problem in terms of smaller versions of itself.

Example:

```cpp
factorial(n)
```

Mathematically:

```text
fact(n) = n × fact(n-1)
```

Base Case:

```text
fact(0) = 1
```

---

# Factorial Using Recursion

Factorial:

```text
n! = n × (n-1) × (n-2) × ... × 1
```

Example:

```text
5! = 5 × 4 × 3 × 2 × 1 = 120
```

### Recursive Formula

```text
fact(n) = n × fact(n-1)
```

### Base Case

```text
fact(0) = 1
```

### Code

```cpp
int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

### Dry Run

```text
factorial(5)

5 * factorial(4)
5 * 4 * factorial(3)
5 * 4 * 3 * factorial(2)
5 * 4 * 3 * 2 * factorial(1)
5 * 4 * 3 * 2 * 1
= 120
```

---

# Time Complexity in Recursion

General Formula:

```text
Time Complexity
=
Total Recursive Calls
×
Work Done Per Call
```

Example:

```cpp
factorial(n)
```

Recursive Calls:

```text
n
```

Work per Call:

```text
O(1)
```

Therefore:

```text
Time Complexity = O(n)
```

---

# Space Complexity in Recursion

Space complexity is determined by:

```text
Maximum Depth of Call Stack
```

For:

```cpp
factorial(n)
```

Stack:

```text
fact(n)
fact(n-1)
fact(n-2)
...
fact(1)
```

Depth:

```text
n
```

Therefore:

```text
Space Complexity = O(n)
```

---

# Sum of First N Numbers

Problem:

```text
1 + 2 + 3 + ... + n
```

### Recursive Formula

```text
sum(n) = n + sum(n-1)
```

### Base Case

```text
sum(1) = 1
```

### Code

```cpp
int sumN(int n)
{
    if(n == 1)
        return 1;

    return n + sumN(n - 1);
}
```

### Dry Run

```text
sumN(4)

4 + sumN(3)
4 + 3 + sumN(2)
4 + 3 + 2 + sumN(1)
4 + 3 + 2 + 1

= 10
```

### Complexity

Time:

```text
O(n)
```

Space:

```text
O(n)
```

---

# Advantages of Recursion

- Simple and elegant code
- Naturally solves divide-and-conquer problems
- Useful for trees and graphs
- Reduces code complexity in some problems

---

# Disadvantages of Recursion

- Extra memory used by call stack
- Can cause stack overflow for deep recursion
- Usually slower than iterative solutions
- Debugging can be harder

---

# Common Mistakes

### Missing Base Case

```cpp
func(n)
{
    return func(n-1);
}
```

Causes:

```text
Infinite Recursion
```

---

### Incorrect Base Case

Stopping too early or too late can produce wrong answers.

---

### Not Reducing Problem Size

```cpp
func(n)
{
    func(n);
}
```

Problem size never decreases.

Infinite recursion occurs.

---

# Recursion Checklist

Before writing a recursive solution:

1. What is the smallest possible problem?
2. What is the base case?
3. How can the problem be reduced?
4. What recursive call should be made?
5. What should be returned after the recursive call?

---

# Memory Trick

```text
Recursion =
Base Case
+
Self Call
+
Smaller Problem
```

Always think:

```text
Stop Condition
↓
Smaller Problem
↓
Recursive Call
```
