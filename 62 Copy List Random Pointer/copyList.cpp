// https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    unordered_map<Node *, Node *> m;
    Node *newhead = new Node(head->val);
    Node *curr = head->next;
    Node *newcurr = newhead;
    m[head] = newhead;
    while (curr != nullptr)
    {
        Node *copyNode = new Node(curr->val);
        newcurr->next = copyNode;
        m[curr] = copyNode;
        newcurr = newcurr->next;
        curr = curr->next;
    }
    curr = head;
    newcurr = newhead;
    while (curr != nullptr)
    {

        newcurr->random = m[curr->random];
        curr = curr->next;
        newcurr = newcurr->next;
    }

    return newhead;
}
int main()
{

    return 0;
}