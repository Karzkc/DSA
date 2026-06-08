 https://leetcode.com/problems/count-primes/
 Sieve of Eratosthenes
# Count Primes

## Intuition
We need to count how many prime numbers exist strictly less than `n`.

 Checking every number individually for primality would be slow.

Instead, we use the **Sieve of Eratosthenes**, which marks multiples of prime numbers as non-prime.

---

## Key Insight
- Every multiple of a prime number is not prime.
- Start with all numbers marked as prime.
- When a prime is found, mark all its multiples as non-prime.
- Count the numbers that remain prime.

---

## Approach
1. Create a boolean array `isPrime` initialized to `true`.
2. Traverse from `2` to `n-1`.
3. If current number is prime:
   - Increment count.
   - Mark all multiples of that number as non-prime.
4. Return the count.

---

## Complexity
### Current Implementation
- **Time:** `O(n log log n)` (Sieve idea)
- **Space:** `O(n)`

---

## Code
```cpp
int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }

        for (int j = i * 2; j < n; j += i) {
            isPrime[j] = false;
        }
    }

    return count;
}
```