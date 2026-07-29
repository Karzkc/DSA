#include <iostream>
#include <iterator>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }
        Node *curr = head;
        head = head->next;
        head->prev = nullptr;
        curr->next = nullptr;
        delete curr;
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }
        Node *curr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        curr->prev = NULL;
        delete curr;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    DoublyList dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.push_front(3);
    dl.push_back(10);
    dl.push_back(11);
    dl.pop_back();
    dl.pop_front();
    dl.display();
    return 0;
}