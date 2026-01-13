#pragma once
#include <stdexcept>

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

private:
    Node* root;
    int node_count;

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    bool insert(Node*& node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            ++node_count;
            return true;
        }
        if (item < node->value) {
            return insert(node->left, item);
        } else if (item > node->value) {
            return insert(node->right, item);
        } else {
            return false;
        }
    }

    bool remove(Node*& node, T item) {
        if (node == nullptr) return false;
        if (item < node->value) {
            return remove(node->left, item);
        } else if (item > node->value) {
            return remove(node->right, item);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                // Leaf node
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* successor = find_min(node->right);
                node->value = successor->value;
                remove(node->right, successor->value);
            }
            --node_count;
            return true;
        }
    }

    Node* find_min(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool contains(Node* node, T item) const {
        if (node == nullptr) return false;
        if (item < node->value) {
            return contains(node->left, item);
        } else if (item > node->value) {
            return contains(node->right, item);
        } else {
            return true;
        }
    }

public:
    BST() : root(nullptr), node_count(0) {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        return insert(root, item);
    }

    bool remove(Node*& node, T item) {
        if (node == nullptr) return false;

        if (item < node->value) {
            return remove(node->left, item);
        } else if (item > node->value) {
            return remove(node->right, item);
        } else {

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* predecessor = find_max(node->left);
                node->value = predecessor->value;
                remove(node->left, predecessor->value);
            }
            --node_count;
            return true;
        }
    }

    Node* find_max(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }


    bool contains(T item) const {
        return contains(root, item);
    }

    void clear() {
        clear(root);
        root = nullptr;
        node_count = 0;
    }

    int size() const {
        return node_count;
    }
};
