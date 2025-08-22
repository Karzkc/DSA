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