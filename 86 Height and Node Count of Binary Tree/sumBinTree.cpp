#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->val;
}