#include <iostream>
using namespace std;

int main()
{
    vector<vector<
        int>>
        matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 2d vectors have a unique property that we can store unevenly sized rows in them
    // for eg we can have a 2d vector like this -
    vector<vector<int>> unevenMatrix = {
        {1, 2, 3, 4},
        {5, 6},
        {7, 8, 9}};

    return 0;
}