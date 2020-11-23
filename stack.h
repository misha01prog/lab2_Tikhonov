#pragma once
#include "ComplexNumber.h"

#define T ComplexNumber, Sign

class Stack {
public:
    struct Node {
        pair<T> value;
        Node* next = nullptr;
    };

    ~Stack() { while (head) { Pop(); } }

    void Push(const pair<T>& value);
    void Pop();
    int Size() const;

    Node* Top() { return head; }
    const Node* Top() const { return head; }
    bool operator==(const Stack& other);
    void operator=(const Stack& other);

private:
    Node* head = nullptr;
};
