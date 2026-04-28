#include <iostream>
using namespace std;

string checkPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return "not Prime";
        }
    }
    return "Prime";
}

int main()
{

    int num;
    cout << "Enter a number:- " << endl;
    cin >> num;

    cout << num << " is " << checkPrime(num) << endl;

    return 0;
}