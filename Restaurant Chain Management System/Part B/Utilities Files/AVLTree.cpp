#include <iostream>
#include "AVLTree.h"

using namespace std;

#include "AVLTree.h" // Include the header file

// Definitions for member functions

template <typename Comparable>
AVLTree<Comparable>::AVLTree() : root{nullptr} {}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree &rhs) : root{nullptr} {
    root = clone(rhs.root);
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(AVLTree &&rhs) : root{rhs.root} {
    rhs.root = nullptr;
}

template <typename Comparable>
AVLTree<Comparable>::~AVLTree() {
    makeEmpty(root);
}

template <typename Comparable>
AVLTree<Comparable> &AVLTree<Comparable>::operator=(const AVLTree &rhs) {
    if (this != &rhs) {
        makeEmpty(root);
        root = clone(rhs.root);
    }
    return *this;
}

template <typename Comparable>
AVLTree<Comparable> &AVLTree<Comparable>::operator=(AVLTree &&rhs) {
    std::swap(root, rhs.root);
    return *this;
}

template <typename Comparable>
const Comparable &AVLTree<Comparable>::findMin() const {
    return findMin(root)->element;
}

template <typename Comparable>
const Comparable &AVLTree<Comparable>::findMax() const {
    return findMax(root)->element;
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable &x) const {
    return contains(x, root);
}

template <typename Comparable>
bool AVLTree<Comparable>::isEmpty() const {
    return root == nullptr;
}

template <typename Comparable>
void AVLTree<Comparable>::printTree() const {
    printTree(root, std::cout);
}

template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable &x) {
    insert(x, root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(Comparable &&x) {
    insert(std::move(x), root);
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable &x) {
    remove(x, root);
}

template <typename Comparable>
typename AVLTree<Comparable>::AVLNode *AVLTree<Comparable>::findMin(AVLNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
typename AVLTree<Comparable>::AVLNode *AVLTree<Comparable>::findMax(AVLNode *t) const {
    if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
    return t;
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable &x, AVLNode *t) const {
    if (t == nullptr)
        return false;
    else if (x < t->element)
        return contains(x, t->left);
    else if (t->element < x)
        return contains(x, t->right);
    else
        return true; // Match
}

template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode *&t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
void AVLTree<Comparable>::printTree(AVLNode *t, std::ostream &out) const {
    if (t != nullptr) {
        printTree(t->left, out);
        out << t->element << " ";
        printTree(t->right, out);
    }
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable &x, AVLNode *&t) {
    if (t == nullptr)
        t = new AVLNode{x, nullptr, nullptr};
    else if (x < t->element) {
        insert(x, t->left);
        balance(t); // Ensure balance after insertion
    } else if (t->element < x) {
        insert(x, t->right);
        balance(t); // Ensure balance after insertion
    }
    // Duplicate elements are not allowed; do nothing if x is equal to t->element
}

template <typename Comparable>
void AVLTree<Comparable>::insert(Comparable &&x, AVLNode *&t) {
    if (t == nullptr)
        t = new AVLNode{std::move(x), nullptr, nullptr};
    else if (x < t->element) {
        insert(std::move(x), t->left);
        balance(t); // Ensure balance after insertion
    } else if (t->element < x) {
        insert(std::move(x), t->right);
        balance(t); // Ensure balance after insertion
    }
    // Duplicate elements are not allowed; do nothing if x is equal to t->element
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable &x, AVLNode *&t) {
    if (t == nullptr)
        return; // Item not found; do nothing
    if (x < t->element) {
        remove(x, t->left);
        balance(t); // Ensure balance after removal
    } else if (t->element < x) {
        remove(x, t->right);
        balance(t); // Ensure balance after removal
    } else if (t->left != nullptr && t->right != nullptr) { // Two children
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
        balance(t); // Ensure balance after removal
    } else {
        AVLNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        balance(t); // Ensure balance after removal
    }
}

template <typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode *&k2) {
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    updateHeight(k2);
    updateHeight(k1);
    k2 = k1;
}

template <typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode *&k1) {
    AVLNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    updateHeight(k1);
    updateHeight(k2);
    k1 = k2;
}

template <typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode *&k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode *&k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

template <typename Comparable>
int AVLTree<Comparable>::height(AVLNode *t) const {
    return (t == nullptr) ? -1 : t->height;
}

template <typename Comparable>
int AVLTree<Comparable>::balanceFactor(AVLNode *t) const {
    return height(t->left) - height(t->right);
}

template <typename Comparable>
void AVLTree<Comparable>::updateHeight(AVLNode *&t) {
    t->height = 1 + std::max(height(t->left), height(t->right));
}

template <typename Comparable>
void AVLTree<Comparable>::balance(AVLNode *&t) {
    if (t == nullptr)
        return;

    if (balanceFactor(t) == 2) {
        if (balanceFactor(t->left) == -1)
            doubleWithLeftChild(t);
        else
            rotateWithLeftChild(t);
    } else if (balanceFactor(t) == -2) {
        if (balanceFactor(t->right) == 1)
            doubleWithRightChild(t);
        else
            rotateWithRightChild(t);
    }

    updateHeight(t);
}
