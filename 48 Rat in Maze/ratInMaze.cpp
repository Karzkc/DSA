// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solveMaze(vector<vector<int>> &maze, vector<string> &ans, string curr, int row, int col)
{
    int n = maze.size();
    if (col < 0 || row < 0 || col >= n || row >= n || maze[row][col] == 0 || maze[row][col] == -1)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(curr);
        return;
    }

    maze[row][col] = -1;
    solveMaze(maze, ans, curr + "D", row + 1, col);
    solveMaze(maze, ans, curr + "L", row, col - 1);
    solveMaze(maze, ans, curr + "R", row, col + 1);
    solveMaze(maze, ans, curr + "U", row - 1, col);
    maze[row][col] = 1;
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> ans;
    // vector<vector<bool>> isVisited(n, vector<bool>(n, false)); // we can optimize this further
    string curr = "";
    solveMaze(maze, ans, curr, 0, 0);

    return ans;
}

int main()
{

    return 0;
}