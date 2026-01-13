#pragma once
#include <algorithm>

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

private:
    Node* root;
    int treeSize;

    int getHeight(Node* node) const {
        return (node == nullptr) ? 0 : node->height;
    }

    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }

    void promoteLeft(Node*& root) {
        Node* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        updateHeight(root);
        updateHeight(newRoot);
        root = newRoot;
    }

    void promoteRight(Node*& root) {
        Node* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        updateHeight(root);
        updateHeight(newRoot);
        root = newRoot;
    }

    void rebalance(Node*& root) {
        if (root == nullptr) return;

        updateHeight(root);
        int balance = getHeight(root->right) - getHeight(root->left);

        if (balance > 1) {
            if (getHeight(root->right->left) > getHeight(root->right->right)) {
                promoteLeft(root->right);
            }
            promoteRight(root);
        } else if (balance < -1) {
            if (getHeight(root->left->right) > getHeight(root->left->left)) {
                promoteRight(root->left);
            }
            promoteLeft(root);
        }

        updateHeight(root);
    }

    bool insert(Node*& root, T item) {
        if (root == nullptr) {
            root = new Node(item);
            treeSize++;
            return true;
        }
        if (item == root->value) return false;
        if (item < root->value) {
            if (insert(root->left, item)) {
                rebalance(root);
                return true;
            }
        } else {
            if (insert(root->right, item)) {
                rebalance(root);
                return true;
            }
        }
        return false;
    }

    bool remove(Node*& root, T item) {
        if (root == nullptr) return false;

        if (item < root->value) {
            if (remove(root->left, item)) {
                rebalance(root);
                return true;
            }
        } else if (item > root->value) {
            if (remove(root->right, item)) {
                rebalance(root);
                return true;
            }
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                Node* toDelete = root;
                root = root->left;
                delete toDelete;
            } else if (root->left == nullptr && root->right != nullptr) {
                Node* toDelete = root;
                root = root->right;
                delete toDelete;
            } else {
                Node* successor = root->right;
                while (successor->left != nullptr) successor = successor->left;
                root->value = successor->value;
                remove(root->right, successor->value);
            }
            treeSize--;
            rebalance(root);
            return true;
        }
        return false;
    }

    bool contains(Node* root, T item) const {
        if (root == nullptr) return false;
        if (item == root->value) return true;
        return item < root->value ? contains(root->left, item) : contains(root->right, item);
    }

    void clear(Node*& root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }

public:
    AVL() : root(nullptr), treeSize(0) {}

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        return insert(root, item);
    }

    bool remove(T item) {
        return remove(root, item);
    }

    bool contains(T item) const {
        return contains(root, item);
    }

    void clear() {
        clear(root);
        treeSize = 0;
    }

    int size() const {
        return treeSize;
    }
};
