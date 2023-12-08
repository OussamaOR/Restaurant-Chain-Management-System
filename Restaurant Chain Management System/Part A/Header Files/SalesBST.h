#pragma once
#ifndef SALESBST_H
#define SALESBST_H
#include "Restaurant-Chain-Management-System/Restaurant Chain Management System/Part A/Source Files/Date.cpp"
#include <iostream>
#include <functional> 


struct DailySale
{
    Date date;
    double dailySaleAmount;

    // getters
    Date getDate() const { return date; }
    double getDailySaleAmount() const { return dailySaleAmount; }

    // setters
    void setDate(const Date &newDate) { date = newDate; }
    void setDailySaleAmount(double amount) { dailySaleAmount = amount; }
};

// Class representing a Binary Search Tree for sales
class salesBST
{
public:
    // Constructors and Destructor
    salesBST();
    salesBST(const salesBST &rhs);
    salesBST(salesBST &&rhs);
    ~salesBST();

    // Basic operations
    void insert(const DailySale &dailySale);
    void remove(const Date &date);
    bool isEmpty() const;
    bool contains(const Date &date) const;

    // Function to return sales at a specific date
    DailySale getSalesAtDate(const Date &date) const;

    // The following three functions are similar, but implementing them separately is better
    // Function to return sales on a specific period
    double getTotalSalesInPeriod(const Date &start, const Date &end) const;

    // Function to return total sales in a month
    double getTotalSalesInMonth(int month, int year) const;

    // Function to return total sales on a year
    double getTotalSalesInYear(int year) const;

    // Function to return min and max (daily sale)
    // You can add it for the max sale on a month if you see it's useful
    DailySale getMinDailySale() const;
    DailySale getMaxDailySale() const;
    salesBST& operator=(const salesBST& );

private:
    // Structure to represent a node in the BST
    struct BinaryNode
    {
        DailySale dailySale;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const DailySale &theDailySale, BinaryNode *lt, BinaryNode *rt)
            : dailySale{theDailySale}, left{lt}, right{rt} {}

        BinaryNode(DailySale &&theDailySale, BinaryNode *lt, BinaryNode *rt)
            : dailySale{std::move(theDailySale)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    // Private member functions
    void insert(const DailySale &dailySale, BinaryNode *&t);
    void remove(const Date &date, BinaryNode *&t);
    bool contains(const Date &date, BinaryNode *t) const;
    DailySale getSalesAtDate(const Date &date, BinaryNode *t) const;
    double getTotalSalesInPeriod(const Date &start, const Date &end, BinaryNode *t) const;
    double getTotalSalesInMonth(int month, int year, BinaryNode *t) const;
    double getTotalSalesInYear(int year, BinaryNode *t) const;
    DailySale getMinDailySale(BinaryNode *t) const;
    DailySale getMaxDailySale(BinaryNode *t) const;
    BinaryNode *findMin(BinaryNode *t) const;
    BinaryNode *findMax(BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t);
    BinaryNode *clone(BinaryNode *t) const;
    BinaryNode* copyTree(const BinaryNode* ) const;
};

// Implementation of public member functions goes here

#endif
