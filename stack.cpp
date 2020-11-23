#include "stack.h"

int Stack::Size() const {
    const Node* node = this->Top();
    int count = 0;
    while (node != nullptr) {
        node = node->next;
        count++;
    }
    return count;
}

void Stack::Push(const pair<T>& value) {
    Node* node_new = new Node{ value };
    node_new->next = head;
    head = node_new;
}

void Stack::Pop() {
    if (head) {
        Node* new_head = head->next;
        delete head;
        head = new_head;
    }
}

bool Stack::operator==(const Stack& other) {
    auto it1 = this->Top();
    auto it2 = other.Top();
    while (it1 != nullptr || it2 != nullptr) {
        if (!(it1->value.first.getImag() == it2->value.first.getImag()
            && it1->value.first.getReal() == it2->value.first.getReal()
            && it1->value.second == it2->value.second)) {
            return false;
        }
        it1 = it1->next;
        it2 = it2->next;
    }
    return true;
}

void Stack::operator=(const Stack& other) {
    while (head) {
        Pop();
    }
    head = new Node;
    const Node* it_other = other.Top();
    Node* it_this = head;
    while (it_other != nullptr) {
        it_this->value = other.head->value;
        it_this->next = new Node;
        it_this = it_this->next;
        it_other = it_other->next;
    }
    it_this = nullptr;
}
