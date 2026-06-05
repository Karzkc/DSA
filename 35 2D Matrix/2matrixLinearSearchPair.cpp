#include <iostream>
using namespace std;

pair<int, int> LinearSearch(int matrix[][3], int row, int col, int num)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == num)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    pair<int, int> res = LinearSearch(matrix, 3, 3, 8);
    cout << res.first << "," << res.second << endl;
    return 0;
}