#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> m;

    void addNode(Node *newNode)
    {
        Node *old = head->next;
        head->next = newNode;
        old->prev = newNode;

        newNode->next = old;
        newNode->prev = head;
    }

    void delNode(Node *oldNode)
    {
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
    }

    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        int ans = m[key]->val;
        Node *node = m[key];

        delNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if (m.size() == capacity)
        {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */