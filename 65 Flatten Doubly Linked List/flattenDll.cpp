// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
#include <iostream>
#include <iterator>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flatten(Node *head)
{
    if (head == nullptr)
        return head;

    Node *curr = head;

    while (curr != nullptr)
    {

        if (curr->child != nullptr)
        {
            Node *nxt = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = nullptr;

            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            if (nxt != nullptr)
            {
                curr->next = nxt;
                nxt->prev = curr;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{

    return 0;
}