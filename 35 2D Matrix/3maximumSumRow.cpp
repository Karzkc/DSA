#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int ms = 0;
    for (int i = 0; i < 3; i++)
    {
        int cs =0;
        for (int j = 0; j < 3; j++)
        {
            cs += matrix[i][j];
        }
        ms = max(ms, cs);
    }
    cout << ms;

    return 0;
}