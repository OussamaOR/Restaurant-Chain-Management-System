#pragma once
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
template<typename Object>
class BinarySearchTree {
    public:
    struct Node {
        Object data;
        Node* right;
        Node* left;
        Node(const Object& obj):data(obj),left(0),right(0){}
    };
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(const Object& ) ;
    void remove(const Object& );
    void printInOrder() const;
    private:
    Node* insertHelper(Node* root, const Object& value);
    Node* removeHelper(Node* root, const Object& value);
    Node* findMin(Node* root) const;
    void printInOrderHelper(Node* root) const;
    void destroyTree(Node* root);

    private:
    Node* root;
};
#endif