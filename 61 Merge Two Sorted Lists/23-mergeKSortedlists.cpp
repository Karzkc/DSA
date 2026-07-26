// https://leetcode.com/problems/merge-k-sorted-lists/
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *merge2SortedLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr || list2 == nullptr)
    {
        return list1 == nullptr ? list2 : list1;
    }
    if (list1->val <= list2->val)
    {
        list1->next = merge2SortedLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge2SortedLists(list1, list2->next);
        return list2;
    }
}
ListNode *mergeK(vector<ListNode *> &lists, int start, int end)
{
    if (start == end)
    {
        return lists[start];
    }

    int mid = start + (end - start) / 2;
    ListNode *left = mergeK(lists, start, mid);
    ListNode *right = mergeK(lists, mid + 1, end);
    return merge2SortedLists(left, right);
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }
    return mergeK(lists, 0, lists.size() - 1);
}

int main()
{

    return 0;
}