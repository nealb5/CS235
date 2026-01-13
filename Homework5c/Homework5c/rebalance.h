#pragma once
#include <algorithm>

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

void updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

void promote_left(Node*& root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    root = newRoot;
}

void promote_right(Node*& root) {
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
            promote_left(root->right);
        }
        promote_right(root);
    } else if (balance < -1) {
        if (getHeight(root->left->right) > getHeight(root->left->left)) {
            promote_right(root->left);
        }
        promote_left(root);
    }

    updateHeight(root);
}
