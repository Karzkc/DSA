#include <iterator>
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
    if (!cycle)
    {
        return NULL;
    }

    slow = head;
    ListNode *prev = nullptr;
    while (slow != fast)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev = prev->next; // cycle removed;
    return slow;
}