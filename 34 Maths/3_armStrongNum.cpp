#include <iostream>
using namespace std;

int main()
{
    int num = 153;
    int temp = num;
    int sum = 0;
    while (temp != 0)
    {
        int dig = temp % 10;
        sum += (dig * dig * dig);
        temp /= 10;
    }

    if (sum == num)
    {
        cout << num << " is an Armstrong number." << endl;
    }
    else
    {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}