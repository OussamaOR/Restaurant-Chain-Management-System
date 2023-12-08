#include <iostream>
#include <algorithm> // For std::max
#pragma once
template <typename Comparable>
class AVLTree {
public:
    AVLTree();
    AVLTree(const AVLTree &rhs);
    AVLTree(AVLTree &&rhs);
    ~AVLTree();

    AVLTree &operator=(const AVLTree &rhs);
    AVLTree &operator=(AVLTree &&rhs);

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree() const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

private:
    struct AVLNode {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode(const Comparable &theElement, AVLNode *lt, AVLNode *rt, int h = 0)
            : element{theElement}, left{lt}, right{rt}, height{h} {}

        AVLNode(Comparable &&theElement, AVLNode *lt, AVLNode *rt, int h = 0)
            : element{std::move(theElement)}, left{lt}, right{rt}, height{h} {}
    };

    AVLNode *root;

    AVLNode *findMin(AVLNode *t) const;
    AVLNode *findMax(AVLNode *t) const;
    bool contains(const Comparable &x, AVLNode *t) const;
    void makeEmpty(AVLNode *&t);
    void printTree(AVLNode *t, std::ostream &out) const;

    void insert(const Comparable &x, AVLNode *&t);
    void insert(Comparable &&x, AVLNode *&t);
    void remove(const Comparable &x, AVLNode *&t);

    // AVL rotation functions
    void rotateWithLeftChild(AVLNode *&k2);
    void rotateWithRightChild(AVLNode *&k1);
    void doubleWithLeftChild(AVLNode *&k3);
    void doubleWithRightChild(AVLNode *&k1);
    int height(AVLNode *t) const;
    int balanceFactor(AVLNode *t) const;
    void updateHeight(AVLNode *&t);
    void balance(AVLNode *& t);
};

// Definitions for member functions...


