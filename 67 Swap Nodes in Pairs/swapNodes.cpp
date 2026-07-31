// https://leetcode.com/problems/swap-nodes-in-pairs/description/
#include <iostream>
#include <iterator>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *first = head;
    ListNode *sec = head->next;
    ListNode *curr = nullptr;

    while (first != nullptr && sec != nullptr)
    {
        ListNode *third = sec->next;
        sec->next = first;
        first->next = third;

        if (curr != nullptr)
        {
            curr->next = sec;
        }
        else
        {
            head = sec;
        }

        curr = first;
        first = third;

        if (third != nullptr)
        {
            sec = third->next;
        }
        else
        {
            sec = nullptr;
        }
    }
    return head;
}

int main()
{

    return 0;
}