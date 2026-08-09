#include <iostream>
#include <list>
using namespace std;

class Stack
{
    list<int> data;

public:
    void push(int num)
    {
        data.push_front(num);
    }

    void pop()
    {
        if (data.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        data.pop_front();
    }

    int top()
    {
        if (data.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }

        return data.front();
    }

    bool empty()
    {
        return data.empty();
    }

    int size()
    {
        return data.size();
    }

    void display()
    {
        if (data.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements: \n";
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            cout << "| " << *it << " |\n";
        }
        cout << "____\n";
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Initial stack:\n";
    s.display();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "After pop:\n";
    s.display();

    return 0;
}