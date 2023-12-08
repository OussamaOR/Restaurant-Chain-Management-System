#include "salesBST.h"
#include "Date.h"
#include <iostream>

// Constructors

salesBST::salesBST() : root(nullptr) {}

salesBST::salesBST(const salesBST &rhs) : root(clone(rhs.root)) {}

salesBST::salesBST(salesBST &&rhs) : root(rhs.root) {
    rhs.root = nullptr;
}

salesBST::~salesBST() {
    makeEmpty(root);
}

// Public member functions

void salesBST::insert(const DailySale &dailySale) {
    insert(dailySale, root);
}

void salesBST::remove(const Date &date) {
    remove(date, root);
}

bool salesBST::isEmpty() const {
    return root == nullptr;
}

bool salesBST::contains(const Date &date) const {
    return contains(date, root);
}

DailySale salesBST::getSalesAtDate(const Date &date) const {
    return getSalesAtDate(date, root);
}

double salesBST::getTotalSalesInPeriod(const Date &start, const Date &end) const {
    return getTotalSalesInPeriod(start, end, root);
}

double salesBST::getTotalSalesInMonth(int month, int year) const {
    return getTotalSalesInMonth(month, year, root);
}

double salesBST::getTotalSalesInYear(int year) const {
    return getTotalSalesInYear(year, root);
}

DailySale salesBST::getMinDailySale() const {
    return getMinDailySale(root);
}

DailySale salesBST::getMaxDailySale() const {
    return getMaxDailySale(root);
}

// Private member functions

void salesBST::insert(const DailySale &dailySale, BinaryNode *&t) {
    if (t == nullptr)
        t = new BinaryNode{dailySale, nullptr, nullptr};
    else if (dailySale.date < t->dailySale.date)
        insert(dailySale, t->left);
    else if (t->dailySale.date < dailySale.date)
        insert(dailySale, t->right);
    // else: Duplicate; do nothing
}

void salesBST::remove(const Date &date, BinaryNode *&t) {
    if (t == nullptr)
        return; // Item not found; do nothing

    if (date < t->dailySale.date)
        remove(date, t->left);
    else if (t->dailySale.date < date)
        remove(date, t->right);
    else if (t->left != nullptr && t->right != nullptr) // Two children
    {
        t->dailySale = findMin(t->right)->dailySale;
        remove(t->dailySale.date, t->right);
    }
    else {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

bool salesBST::contains(const Date &date, BinaryNode *t) const {
    if (t == nullptr)
        return false;
    else if (date < t->dailySale.date)
        return contains(date, t->left);
    else if (t->dailySale.date < date)
        return contains(date, t->right);
    else
        return true; // Match
}

DailySale salesBST::getSalesAtDate(const Date &date, BinaryNode *t) const {
    if (t == nullptr)
        return DailySale{Date{}, 0.0}; // Return an empty DailySale if not found

    if (date < t->dailySale.date)
        return getSalesAtDate(date, t->left);
    else if (t->dailySale.date < date)
        return getSalesAtDate(date, t->right);
    else
        return t->dailySale; // Match
}

double salesBST::getTotalSalesInPeriod(const Date &start, const Date &end, BinaryNode *t) const {
    if (t == nullptr)
        return 0.0;

    if (end < t->dailySale.date)
        return getTotalSalesInPeriod(start, end, t->left);
    else if (t->dailySale.date < start)
        return getTotalSalesInPeriod(start, end, t->right);
    else
        return t->dailySale.dailySaleAmount +
               getTotalSalesInPeriod(start, end, t->left) +
               getTotalSalesInPeriod(start, end, t->right);
}

double salesBST::getTotalSalesInMonth(int month, int year, BinaryNode *t) const {
    if (t == nullptr)
        return 0.0;

    if (year < t->dailySale.date.getYear() || (year == t->dailySale.date.getYear() && month < t->dailySale.date.getMonth()))
        return getTotalSalesInMonth(month, year, t->left);
    else if (t->dailySale.date.getYear() < year || (year == t->dailySale.date.getYear() && t->dailySale.date.getMonth() < month))
        return getTotalSalesInMonth(month, year, t->right);
    else
        return t->dailySale.dailySaleAmount +
               getTotalSalesInMonth(month, year, t->left) +
               getTotalSalesInMonth(month, year, t->right);
}

double salesBST::getTotalSalesInYear(int year, BinaryNode *t) const {
    if (t == nullptr)
        return 0.0;

    if (year < t->dailySale.date.getYear())
        return getTotalSalesInYear(year, t->left);
    else if (t->dailySale.date.getYear() < year)
        return getTotalSalesInYear(year, t->right);
    else
        return t->dailySale.dailySaleAmount +
               getTotalSalesInYear(year, t->left) +
               getTotalSalesInYear(year, t->right);
}

DailySale salesBST::getMinDailySale(BinaryNode *t) const {
    if (t == nullptr)
        return DailySale{Date{}, 0.0}; // Return an empty DailySale if the tree is empty

    while (t->left != nullptr)
        t = t->left;

    return t->dailySale;
}

DailySale salesBST::getMaxDailySale(BinaryNode *t) const {
    if (t == nullptr)
        return DailySale{Date{}, 0.0}; // Return an empty DailySale if the tree is empty

    while (t->right != nullptr)
        t = t->right;

    return t->dailySale;
}

salesBST::BinaryNode *salesBST::findMin(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;

    while (t->left != nullptr)
        t = t->left;

    return t;
}

salesBST::BinaryNode *salesBST::findMax(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;

    while (t->right != nullptr)
        t = t->right;

    return t;
}

void salesBST::makeEmpty(BinaryNode *&t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

salesBST::BinaryNode *salesBST::clone(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->dailySale, clone(t->left), clone(t->right)};
}

// Implementation of copy assignment operator
salesBST& salesBST::operator=(const salesBST& other) {
    if (this != &other) { // Avoid self-assignment
        makeEmpty(root); // Clear the current tree
        root = copyTree(other.root); // Copy the tree from rhs
    }
    return *this;
}

// Helper function to copy the tree
salesBST::BinaryNode* salesBST::copyTree(const BinaryNode* t) const {
    if (t == nullptr) {
        return nullptr;
    }

    // Recursively copying the nodes
    BinaryNode* newNode = new BinaryNode(t->dailySale, copyTree(t->left), copyTree(t->right));
    return newNode;
}


