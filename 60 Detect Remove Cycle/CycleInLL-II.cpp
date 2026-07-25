// https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
#include <iterator>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool cycle = false;
    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        slow = head;
        while (slow != fast)
        {

            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    return NULL;
}
int main()
{

    return 0;
}