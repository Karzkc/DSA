// https://leetcode.com/problems/sudoku-solver/description/
#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char dig)
{

    for (int i = 0; i < 9; i++)
    {
        if (dig == board[row][i])
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (dig == board[i][col])
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
            if (dig == board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokuSolver(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    int nrow = row, ncol = col + 1;
    if (ncol == 9)
    {
        nrow = row + 1;
        ncol = 0;
    }
    if (board[row][col] != '.')
    {
        return sudokuSolver(board, nrow, ncol);
    }

    for (char dig = '1'; dig <= '9'; dig++)
    {

        if (isValid(board, row, col, dig))
        {
            board[row][col] = dig;
            if (sudokuSolver(board, nrow, ncol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board) { sudokuSolver(board, 0, 0); }
int main()
{

    return 0;
}