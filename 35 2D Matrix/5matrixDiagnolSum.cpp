#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3] = {
        {10, 2, 3},
        {4, 50, 6},
        {7, 8, 9}};
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += matrix[i][i] + matrix[i][3 - i - 1]; // middle element included twice
    }
    cout << sum;

    return 0;
}