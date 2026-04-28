https://leetcode.com/problems/powx-n/description/

# Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

-2^31 <= n <= 2^31-1
if we use normal loop of O(n) it will give TLE as this goes till 10^8 integers only but here its 2^31


## Intuition
A naive approach multiplies `x` by itself `n` times → `O(n)` → too slow for large `n`.

Instead, we use **Binary Exponentiation** to reduce time to `O(log n)`.

## Key Insight
- Any number `n` can be represented in binary.
- We square the base (`x`) at each step.
- If the current bit of `n` is `1`, we multiply it into the result.

👉 This avoids repeated multiplication and reduces operations drastically.

## Approach
- Handle negative exponent:
  - Convert `x` → `1/x`
  - Convert `n` → positive
- Initialize `res = 1`
- While `n > 0`:
  - If `n` is odd → multiply `res *= x`
  - Square the base → `x *= x`
  - Divide exponent → `n /= 2`
- Return result

## Complexity
- **Time:** `O(log n)`
- **Space:** `O(1)`

## Code
```cpp
double myPow(double x, int n)
{
    double res = 1;
    long bin = n;

    if (n < 0)
    {
        x = 1 / x;
        bin = -bin;
    }

    while (bin > 0)
    {
        if (bin % 2 == 1)
        {
            res *= x;
        }

        x *= x;
        bin /= 2;
    }

    return res;
}
```