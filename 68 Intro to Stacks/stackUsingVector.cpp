#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> s;

public:
    void push(int num)
    {
        s.push_back(num);
    }

    void pop()
    {
        if (!s.empty())
            s.pop_back();
        else
            cout << "Stack is empty!\n";
    }

    int top()
    {
        if (!s.empty())
            return s.back();
        else
        {
            cout << "Stack is empty!\n";
            return -1;
        }
    }

    bool empty()
    {
        return s.empty();
    }

    int size()
    {
        return s.size();
    }

    void display()
    {
        if (s.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        for (int i = s.size() - 1; i >= 0; --i)
        {
            cout << " | " << s[i] << " | " << endl;
        }
        cout << "  ____\n";
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "After pop:\n";
    s.display();

    return 0;
}