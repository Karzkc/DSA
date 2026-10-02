#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

static int i = -1;
Node *buildTree(vector<int> preorder)
{
    i++;
    if (preorder[i] == -1)
    {
        return nullptr;
    }

    Node *root = new Node(preorder[i]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == nullptr)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(nullptr);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    cout << "Pre Order:- ";
    preOrder(root);
    cout << "in Order:- ";
    inOrder(root);
    cout << "Post Order:- ";
    postOrder(root);
    cout << endl;
    cout << "Level Order:- " << endl;
    LevelOrder(root);
    return 0;
}