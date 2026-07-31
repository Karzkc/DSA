#include <iostream>
#include <iterator>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = nullptr;
    }
    void insertHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insertTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {

            Node *temp = head;
            head = head->next;
            tail->next = head;

            temp->next = nullptr;
            delete temp;
        }
    }
    void deleteTail()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = head->next;
        cout << head->data << "->";

        while (temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    CircularList cl;
    cl.insertHead(1);
    cl.insertHead(2);
    cl.insertHead(3);
    cl.insertTail(67);
    cl.insertTail(68);
    cl.deleteHead();
    cl.deleteTail();
    cl.display();
    return 0;
}