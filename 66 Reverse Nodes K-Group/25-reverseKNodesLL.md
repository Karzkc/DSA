https://leetcode.com/problems/reverse-nodes-in-k-group/
# LC 25 - Reverse Nodes in k-Group

## Intuition

Treat the linked list as blocks of size `k`.

For each block:

1. Check if `k` nodes exist.
2. Reverse those `k` nodes.
3. Recursively solve the remaining list.
4. Connect the tail of the reversed block to the processed remainder.

---

## Algorithm

```cpp
reverseKGroup(head)

1. If fewer than k nodes remain:
       return head

2. Save pointer to the next group.

3. Reverse the first k nodes.

4. Recursively reverse the remaining list.

5. Connect the current group's tail to the returned list.

6. Return the new head of the reversed group.