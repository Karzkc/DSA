#include <iostream>
#include <vector>
using namespace std;
// easy as hell why th is this in hard lol , jus copy and paste prev prob
int ans = 0;
bool isValid(vector<string> &board, int n, int row, int col)
{

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

void getQueen(vector<string> &board, int n, int row)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(board, n, row, i))
        {
            board[row][i] = 'Q';
            getQueen(board, n, row + 1);
            board[row][i] = '.';
        }
    }
}

int totalNQueens(int n)
{

    vector<string> board(n, string(n, '.'));
    getQueen(board, n, 0);
    return ans;
}

int main()
{

    return 0;
}