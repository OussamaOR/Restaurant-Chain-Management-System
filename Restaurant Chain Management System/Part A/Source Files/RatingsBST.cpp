#include "RatingsBST.h"
//Constructors
ratingsBST::ratingsBST(){
    root=nullptr;
}
ratingsBST::ratingsBST(MonthlyRating &rating):root(new MonthlyRating(rating)) {}
// Destructor
ratingsBST::~ratingsBST(){makeEmpty(root);}


//insert functions with different parameters
void ratingsBST::insertRating(MonthlyRating &rating)
{
    root = insertHelper(root, rating.get_RatingDates(), rating.getRatings());
}

void ratingsBST::insertRating(std::pair<int, int> date, std::vector<int> ratings)
{
    MonthlyRating newRating;
    newRating.set_RatingDates(date.first, date.second);
    newRating.setRatings(ratings);
    insertRating(newRating);
}


// remove functions with different parameters
void ratingsBST::remove(MonthlyRating &rating)
{
    root = removeHelper(root, rating.get_RatingDates(), rating.getRatings());
}
void ratingsBST::remove(std::pair<int, int> date, std::vector<int> ratings)
{
    MonthlyRating rating;
    rating.set_RatingDates(date.first, date.second);
    rating.setRatings(ratings);
    remove(rating);
}

// Function to print MonthlyRatings 
void ratingsBST::print(MonthlyRating *root)
{
    printHelper(root);
}

// function to make the BST empty
bool ratingsBST::makeEmpty(MonthlyRating *root)
{
    if (root == nullptr)
        return true;
    
    if (!makeEmpty(root->getLeftChild()) || !makeEmpty(root->getRightChild()))
    {
        return false;
    }
    delete root;

    return true;
}

//helper functions 
MonthlyRating *ratingsBST::insertHelper(MonthlyRating *root, std::pair<int, int> date, std::vector<int> ratings)
{
    if (root == nullptr)
    {
        MonthlyRating *newNode = new MonthlyRating();
        newNode->set_RatingDates(date.first, date.second);
        newNode->setRatings(ratings);
        return newNode;
    }

    if (date < root->get_RatingDates())
    {
        root->setLeftChild(insertHelper(root->getLeftChild(), date, ratings));
    }
    else if (date > root->get_RatingDates())
    {
        root->setRightChild(insertHelper(root->getRightChild(), date, ratings));
    }

    return root;
}
MonthlyRating *ratingsBST::removeHelper(MonthlyRating *root, std::pair<int, int> date, std::vector<int> ratings)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (date < root->get_RatingDates())
    {
        root->setLeftChild(removeHelper(root->getLeftChild(), date, ratings));
    }
    else if (date > root->get_RatingDates())
    {
        root->setRightChild(removeHelper(root->getRightChild(), date, ratings));
    }
    else
    {
        // Node having one child 
        if (root->getLeftChild() == nullptr)
        {
            MonthlyRating *temp = root->getRightChild();
            delete root;
            return temp;
        }
        else if (root->getRightChild() == nullptr)
        {
            MonthlyRating *temp = root->getLeftChild();
            delete root;
            return temp;
        }

        // Node with two children
        MonthlyRating *temp = findMin(root->getRightChild());
        *root = *temp;
        root->setRightChild(removeHelper(root->getRightChild(), temp->get_RatingDates(), temp->getRatings()));
    }
    return root;
}
MonthlyRating *ratingsBST::findMin(MonthlyRating *root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->getLeftChild() == nullptr)
    {
        return root;
    }

    return findMin(root->getLeftChild());
}
void ratingsBST::printHelper(MonthlyRating *root) const
{
    if (root == nullptr)
    {
        return;
    }
    printHelper(root->getLeftChild());
    root->printAverageMonthlyRating();
    printHelper(root->getRightChild());
}