#pragma once
#include <stdexcept>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

private:
    Node* head;
    Node* tail;
    int list_size;

public:
    DLList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* new_node = new Node(item);
        new_node->next = head;

        if (head) {
            head->prev = new_node;
        } else {
            tail = new_node;
        }

        head = new_node;
        list_size++;
    }

    void push_back(T item) {
        Node* new_node = new Node(item);
        new_node->prev = tail;

        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;
        }

        tail = new_node;
        list_size++;
    }

    void insert(T item, int position) {
        if (position < 0 || position > list_size) {
            throw std::out_of_range("Index out of range");
        }

        if (position == 0) {
            push_front(item);
        } else if (position == list_size) {
            push_back(item);
        } else {
            Node* new_node = new Node(item);
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            list_size++;
        }
    }

    void pop_front() {
        if (!head) throw std::length_error("List is empty");

        Node* to_delete = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete to_delete;
        list_size--;
    }

    void pop_back() {
        if (!tail) throw std::length_error("List is empty");

        Node* to_delete = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete to_delete;
        list_size--;
    }

    void remove(int position) {
        if (position < 0 || position >= list_size) {
            throw std::out_of_range("Index out of range");
        }

        if (position == 0) {
            pop_front();
        } else if (position == list_size - 1) {
            pop_back();
        } else {
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            list_size--;
        }
    }

    const T& front() const {
        if (!head) throw std::length_error("List is empty");
        return head->value;
    }

    const T& back() const {
        if (!tail) throw std::length_error("List is empty");
        return tail->value;
    }

    const T& at(int index) const {
        if (index < 0 || index >= list_size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    bool contains(const T& item) const {
        Node* current = head;
        while (current) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        return list_size;
    }

    void clear() {
        while (head) {
            Node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        head = nullptr;
        tail = nullptr;
        list_size = 0;
    }
};
