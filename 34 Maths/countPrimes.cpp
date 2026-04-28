// https://leetcode.com/problems/count-primes/
// Sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    if (n <= 2) return 0;

    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = 1LL * i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int primes = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i]) primes++;

    return primes;
}
