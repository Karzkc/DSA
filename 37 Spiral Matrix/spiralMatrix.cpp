// https : // leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> spiral(0);
    int m = matrix.size();
    int n = matrix[0].size();

    int srow = 0, erow = m - 1;
    int scol = 0, ecol = n - 1;
    while (erow > srow && ecol >= scol)
    {

        for (int i = scol; i <= ecol; i++)
        {
            spiral.push_back(matrix[srow][i]);
            // cout << matrix[srow][i] << " srow:" << srow << " erow:" << erow << " scol:" << scol << " ecol:" << ecol << endl;
        }
        srow++;
        for (int i = srow; i <= erow; i++)
        {
            spiral.push_back(matrix[i][ecol]);
            // cout << matrix[i][ecol] << " srow:" << srow << " erow:" << erow << " scol:" << scol << " ecol:" << ecol << endl;
        }
        ecol--;
        
        for (int i = ecol; i >= scol; i--)
        {
            spiral.push_back(matrix[erow][i]);
            // cout << matrix[erow][i] << " srow:" << srow << " erow:" << erow << " scol:" << scol << " ecol:" << ecol << endl;
        }
        erow--;
        for (int i = erow; i >= srow; i--)
        {
            spiral.push_back(matrix[i][scol]);
            // cout << matrix[i][scol] << " srow:" << srow << " erow:" << erow << " scol:" << scol << " ecol:" << ecol << endl;
        }
        scol++;
    }
    return spiral;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 10},
                                  {5, 6, 7, 8, 10},
                                  {5, 6, 7, 8, 10},
                                  {9, 10, 11, 12, 10}};

    vector<int> result = spiralOrder(matrix);

    return 0;
}