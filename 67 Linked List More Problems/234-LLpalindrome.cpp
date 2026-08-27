// https://leetcode.com/problems/palindrome-linked-list/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return true;

    int n = 0;
    ListNode *tail = head;
    while (tail != nullptr)
    {
        tail = tail->next;
        n++;
    }

    ListNode *curr = head;
    int secHalf = (n + 1) / 2;

    for (int i = 0; i < secHalf; i++)
    {
        curr = curr->next;
    }

    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *start = head;
    while (prev != nullptr)
    {
        if (start->val != prev->val)
        {
            return false;
        }
        start = start->next;
        prev = prev->next;
    }
    return true;
}

int main()
{

    return 0;
}