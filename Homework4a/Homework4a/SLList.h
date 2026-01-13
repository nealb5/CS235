#pragma once
#include <iostream>

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : head(nullptr), tail(nullptr), n(0) {}

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        Node* new_node = new Node(item);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        n++;
    }

    void pop_back() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        n--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return n;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = tail = nullptr;
        n = 0;
    }

private:
    Node* head;
    Node* tail;
    int n;
};
