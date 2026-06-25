// https://leetcode.com/problems/valid-sudoku/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col)
{

    for (int i = col + 1; i < 9; i++)
    {
        if (board[row][col] == board[row][i])
        {
            return false;
        }
    }
    for (int i = row + 1; i < 9; i++)
    {
        if ( board[row][col] == board[i][col])
        {
            return false;
        }
    }
    
    int srow = row - row % 3;
    int scol = col - col % 3;
    for (int i = srow; i < srow + 3; i++)
    {
        for (int j = scol; j < scol + 3; j++)
        {
            if (i != row || j != col && board[row][col] == board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && !isValid(board, i, j))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{

    return 0;
}