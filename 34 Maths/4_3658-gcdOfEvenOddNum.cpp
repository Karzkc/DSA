int gcdOfOddEvenSums(int n)
{
    int a = n * (n + 1);
    int b = n * n;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}