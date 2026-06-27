// https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void wordFinder(vector<vector<char>> &board, string word, bool ans, int count, int row, int col)
{
    int m = board.size();
    int n = board[0].size();
    if (col < 0 || row < 0 || col >= n || row >= n || board[row][col] == '.' || count == word.size() || board[row][col] != word[count])
    {
        return;
    }

    if (count == word.size())
    {
        ans == true;
        return;
    }

    board[row][col] == '.';
    count++;
    wordFinder(board, word, ans, count, row + 1, col);
    wordFinder(board, word, ans, count, row, col - 1);
    wordFinder(board, word, ans, count, row, col + 1);
    wordFinder(board, word, ans, count, row - 1, col);
    count--;
    board[row][col] == word[word.size() - count];
}
bool exist(vector<vector<char>> &board, string word)
{
    bool ans = false;
    int count = 0;
    wordFinder(board, word, ans, count, 0, 0);
    return ans;
}

int main()
{

    return 0;
}