#pragma once
template<typename Object>
class BinarySearchTree {
    private:
    struct Node {
        Object data;
        Node* right;
        Node* left;
        Node(const Object& obj):data(obj),left(0),right(0){}
    };
    Node* root;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(const Object& );
    void remove(const Object& );
    void printInOrder() const;
    private:
    Node* insertHelper(Node* root, const Object& value);
    Node* removeHelper(Node* root, const Object& value);
    Node* findMin(Node* root) const;
    void printInOrderHelper(Node* root) const;
    void destroyTree(Node* root);
};