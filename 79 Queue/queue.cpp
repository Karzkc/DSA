#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next =nullptr;
    }
    
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    ~Queue(){
        while (!empty()){
            pop();
        }
    }

    void push(int val){
        Node* newNode = new Node(val);

        if (empty()){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if (empty()){
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr){
            tail = nullptr;
        }
    }

    int front(){
        if (empty()){
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == nullptr;
    }
};

int main() {
    
    return 0;
}