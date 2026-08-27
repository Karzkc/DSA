// https://leetcode.com/problems/reverse-linked-list-ii/description/

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *temp = head;
    ListNode *curr = head;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    int i = 1;

    while (i != right+1 )
    {
        if (i == left)
        {
            curr = temp;
        }
        else if (i > left)
        {
            temp = temp->next;
        }

        if (i >= left)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    return head;
}