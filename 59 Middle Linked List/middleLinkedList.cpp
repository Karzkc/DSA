// https://leetcode.com/problems/middle-of-the-linked-list/description/

#include <iostream>
#include <iterator>
#include <cmath>
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

ListNode *middleNode(ListNode *head)
{
    ListNode *start = head;
    int len = 0;
    while (start != nullptr)
    {
        start = start->next;
        len++;
    }
    int mid = (len / 2) + 1;
    ListNode *curr = head;
    for (int i = 1; i < mid; i++)
    {
        curr = curr->next;
    }
    return curr;
}

int main()
{

    return 0;
}