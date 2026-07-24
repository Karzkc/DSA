#include <iostream>
#include <iterator>
#include <climits>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = nullptr;
    }

    // Add in Start
    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic not static
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    // Add in Last
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }

        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }

    // print ll
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

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Empty LL";
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Pos" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int val)
    {
        Node *temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return i;
            }
            temp = temp->next;
            i++;
        }
        return -1;
    }
    int length()
    {
        Node *start = head;
        int len = 0;
        while (start != nullptr)
        {
            start = start->next;
            len++;
        }
        return len;
    }
};

int main()
{
    List ll;
    ll.push_front(69);

    ll.push_back(67);
    // ll.pop_front();
    // ll.pop_back();
    ll.insert(101, 0);
    cout << ll.search(67) << endl;
    ll.display();
    cout << ll.length();
    return 0;
}