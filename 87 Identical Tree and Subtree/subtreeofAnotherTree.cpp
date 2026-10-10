// https://leetcode.com/problems/subtree-of-another-tree/
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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr || q == nullptr)
    {
        return p == q;
    }

    bool isLeft = isSameTree(p->left, q->left);
    bool isRight = isSameTree(p->right, q->right);
    return isLeft && isRight && p->val == q->val;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr || subRoot == nullptr)
    {
        return root == subRoot;
    }

    if (root->val == subRoot->val && isSameTree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}