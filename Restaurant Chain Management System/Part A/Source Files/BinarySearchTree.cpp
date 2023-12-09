// BinarySearchTree.cpp

#include "../Header Files/BinarySearchTree.h"
#include <iostream>

// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

// Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTree(root);
}

// Public Member Functions

// Insert a value into the tree
template <typename T>
void BinarySearchTree<T>::insert(const T& value)  {
    root = insertHelper(root, value);
}

// Remove a value from the tree
template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    root = removeHelper(root, value);
}

// Print the values of the tree in ascending order
template <typename T>
void BinarySearchTree<T>::printInOrder() const {
    printInOrderHelper(root);
    std::cout << std::endl;
}

// Private Helper Functions

// Helper function for inserting
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insertHelper(Node* root, const T& value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertHelper(root->left, value);
    } else if (value > root->data) {
        root->right = insertHelper(root->right, value);
    }

    return root;
}
// Helper function for removing
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::removeHelper(Node* root, const T& value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->data) {
        root->left = removeHelper(root->left, value);
    } else if (value > root->data) {
        root->right = removeHelper(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        root->data = findMin(root->right)->data;
        root->right = removeHelper(root->right, root->data);
    }

    return root;
}

// Helper function to find the node with the minimum value in a subtree
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMin(Node* root) const {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Helper function for in-order traversal
template <typename T>
void BinarySearchTree<T>::printInOrderHelper(Node* root) const {
    if (root != nullptr) {
        printInOrderHelper(root->left);
        std::cout << root->data << " ";
        printInOrderHelper(root->right);
    }
}

// Helper function to destroy the tree
template <typename T>
void BinarySearchTree<T>::destroyTree(Node* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

