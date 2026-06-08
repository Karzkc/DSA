# Modulo Arithmetic

## 4 Properties of Modulo

1. **Closure**
   - If `a` and `b` are integers, then `(a + b) % m` and `(a * b) % m` are also integers in the range `0` to `m - 1`.

2. **Addition Property**
   - `(a + b) % m = ((a % m) + (b % m)) % m`

3. **Multiplication Property**
   - `(a * b) % m = ((a % m) * (b % m)) % m`

4. **Subtraction Property**
   - `(a - b) % m = ((a % m) - (b % m) + m) % m`

5. **Idempotent Property**
   - `(((a % m) % m) % m ... ) = a % m`

## About `10^7 + 9`

- `10^7 + 9` equals `10000009`.
- It is often used as a modulus in programming problems when a large prime modulus is needed, although more common values are `10^9 + 7` or `10^9 + 9`.
- When using `10000009` as a modulus, ensure the value is prime or suitable for the intended application.
- In many algorithms, choosing a modulus like `10^7 + 9` helps keep intermediate values within integer limits while preserving modular properties.











