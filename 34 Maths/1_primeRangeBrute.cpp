
#include <iostream>
using namespace std;

void primeRange(int num)
{
    for (int i = 2; i <= num; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << " ";
        }
    }
} 

int main()
{

    int num;
    cout << "Enter a number:- " << endl;
    cin >> num;
    cout << "Prime numbers from 2 to " << num << " are :- " << endl;
    primeRange(num);

    return 0;
}