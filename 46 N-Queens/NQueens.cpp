// https://leetcode.com/problems/n-queens/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isValid(vector<string> &board, int n, int row, int col)
{
    // no need for horizontal as already no extra queen
    
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void getQueen(vector<string> &board, int n, int row,
              vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(board, n, row, i))
        {
            board[row][i] = 'Q';
            getQueen(board, n, row + 1, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    getQueen(board, n, 0, ans);
    return ans;
}

int main()
{

    return 0;
}