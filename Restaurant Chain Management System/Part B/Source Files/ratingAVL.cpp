#include "ratingAVL.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

//Constructors
ratingAVL::ratingAVL()
{
    root=nullptr;
}
ratingAVL::ratingAVL(MonthlyRating &rating):root(new MonthlyRating(rating)) {}
// Destructor
ratingAVL::~ratingAVL()
{
    makeEmpty(root);
}


//insert functions with different parameters
void ratingAVL::insertRatingAVL(MonthlyRating &rating)
{
    root = insertHelperAVL(root, rating.get_RatingDates(), rating.getRatings());
}

void ratingAVL::insertRatingAVL(std::pair<int, int> date, std::vector<int> ratings)
{
    MonthlyRating newRating;
    newRating.set_RatingDates(date.first, date.second);
    newRating.setRatings(ratings);
    insertRatingAVL(newRating);
}


// remove functions with different parameters
void ratingAVL::removeAVL(MonthlyRating &rating)
{
    root = removeHelperAVL(root, rating.get_RatingDates(), rating.getRatings());
}
void ratingAVL::removeAVL(std::pair<int, int> date, std::vector<int> ratings)
{
    MonthlyRating rating;
    rating.set_RatingDates(date.first, date.second);
    rating.setRatings(ratings);
    removeAVL(rating);
}

// Function to print MonthlyRatings
void ratingAVL::printAVL(MonthlyRating *root)
{
    printHelper(root);
}

// function to make the BST empty
bool ratingAVL::makeEmpty(MonthlyRating *root)
{
    if (root == nullptr)
        return true;

    if (!makeEmpty(root->getLeftChild()) || !makeEmpty(root->getRightChild()))
    {
        return false;
    }
    delete root;
    root = nullptr;
    return true;
}
double ratingAVL::getAverageRatingByMonth(MonthlyRating* root,int month, int year )
{
   double ratingInMonth = 0;
    std::pair<int,int> temp = std::make_pair(month,year );
    ratingInMonth = getAverageRatingByMonthHelper(root,temp );
    if (ratingInMonth == -1)
    {
        std::cerr << "this date does not exist " << std::endl;
    }
    else
    {
        if (ratingInMonth == -2)
        {
            std::cerr << "invalid date provided " << std::endl;
        }
        else
        {
            return ratingInMonth;
        }
    }
}
double ratingAVL::getAverageRatingByMonth(MonthlyRating* root,std::pair<int,int> other)
{

    double ratingInMonth = 0;
    ratingInMonth = getAverageRatingByMonthHelper(root,other );
    return ratingInMonth;
}

double ratingAVL::getAverageratingByYear(MonthlyRating* root,int year)
{
    return getAverageratingByYearHelper(root, year);


}

double ratingAVL::getAverageratingByPeriod(MonthlyRating* root,std::pair<int,int> temp,std::pair<int,int> other )
{
    double periodRating = 0;

    if (date1 > date2)
    {
        std::swap(date1, date2);
    }
    periodRating = getAverageratingByPeriodHelper(root, date1, date2);
    if (periodRating == -1)
    {
        std::cerr << "this date does not exist " << std::endl;
    }
    else
    {
        if (periodRating == -2)
        {
            std::cerr << "invalid date provided " << std::endl;
        }
        else
        {
            if (periodRating == -3)
            {
                std::cerr << "one of the dates is not in the tree " << std::endl;
            }
            else
            {
                return periodRating;
            }
        }
    }
}
//helper functions

MonthlyRating *ratingAVL::findMin(MonthlyRating *root) const
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
void ratingAVL::printHelper(MonthlyRating *root) const
{
    if (root == nullptr)
    {
        return;
    }
    printHelper(root->getLeftChild());
    root->printAverageMonthlyRating();
    printHelper(root->getRightChild());
}
double ratingAVL::getAverageRatingByMonthHelper(MonthlyRating* root,std::pair<int,int> other )
{
   double aveRating = 0;

    if (!(checkDate(other)))
    {
        return -2;
    }
    if(!root)
    {
        return -1;
    }
    if(root)
    {
        if((root->get_RatingDates()).first == other.first && (root->get_RatingDates()).second == other.second)
        {
            aveRating = root->averageRating();
            return aveRating;
        }
        else
        {
            if((root->get_RatingDates()).first < other.first || ((root->get_RatingDates()).first== other.first && (root->get_RatingDates()).second < other.second))
            {
                aveRating += getAverageRatingByMonthHelper(root->getRightChild(), other);
            }
            else
            {
                aveRating += getAverageRatingByMonthHelper(root->getLeftChild(), other);
            }
        }
    }
    return aveRating;
}
bool ratingAVL::checkDate(std::pair<int,int> date )
{

    if(date.second <= 1999 )
    {
        return false;
    }
    else
    {
        if( date.first <1 && date.first >= 13)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
double  ratingAVL::getAverageratingByYearHelper(MonthlyRating* root,int year )
{
   if (!root)    return 0;
    double tempYear = 0;
    int countMonth = 0;

    if (root->get_RatingDates().second == year)
    {
        tempYear += root->averageRating();
        countMonth++;
    }

    getAverageratingByYearHelper(root->getRightChild(), year);
     getAverageratingByYearHelper(root->getLeftChild(), year);
    return  static_cast<double>(tempYear) / static_cast<double>(countMonth);
}

double ratingAVL::getAverageratingByPeriodHelper(MonthlyRating* root,std::pair<int,int> firstDate,std::pair<int,int> secondDate)
{
     int countPeriod =0;
    double tempPeriod = 0;
    if (!(checkDate(firstDate) && checkDate(secondDate)))
    {
        return -2;
    }
    if( root == nullptr)
    {
        return -1;
    }
    bool foundMatchingNode = false;

    std::stack<MonthlyRating*> stack;
    MonthlyRating* current = root;

    while (current != nullptr || !stack.empty())
    {
        while (current != nullptr)
        {
            stack.push(current);
            current = current->getLeftChild();
        }

        current = stack.top();
        stack.pop();

        if (current->get_RatingDates() >= firstDate && current->get_RatingDates() <= secondDate)
        {
            tempPeriod += current->averageRating();
            countPeriod++;
            foundMatchingNode = true;
        }

        current = current->getRightChild();
    }

    if (!foundMatchingNode)
    {
        return -3;
    }
    else
        return (countPeriod == 0) ? 0.0 : static_cast<double>(tempPeriod) / static_cast<double>(countPeriod);
}


//the hight function
int ratingAVL::getHeight(MonthlyRating *root)
{
    if (root == nullptr)
        return -1;
    return std::max(getHeight(root->getLeftChild()), getHeight(root->getRightChild())) + 1;
}
// Helper function to get the balance factor of a node
int ratingAVL::getBalanceFactor(MonthlyRating *root)
{
    if (root == nullptr)
        return 0;
    return getHeight(root->getLeftChild()) - getHeight(root->getRightChild());
}

// Helper function to perform right rotation
MonthlyRating *ratingAVL::rotateRight(MonthlyRating *y)
{
    MonthlyRating *x = y->getLeftChild();
    MonthlyRating *T2 = x->getRightChild();

    x->setRightChild(y);
    y->setLeftChild(T2);

    y->setHeight(std::max(getHeight(y->getLeftChild()), getHeight(y->getRightChild())) + 1);
    x->setHeight(std::max(getHeight(x->getLeftChild()), getHeight(x->getRightChild())) + 1);

    return x;
}

// Helper function to perform left rotation
MonthlyRating *ratingAVL::rotateLeft(MonthlyRating *x)
{
    MonthlyRating *y = x->getRightChild();
    MonthlyRating *T2 = y->getLeftChild();

    y->setLeftChild(x);
    x->setRightChild(T2);

    x->setHeight(std::max(getHeight(x->getLeftChild()), getHeight(x->getRightChild())) + 1);
    y->setHeight(std::max(getHeight(y->getLeftChild()), getHeight(y->getRightChild())) + 1);

    return y;
}
MonthlyRating *ratingAVL::balanceAVL(MonthlyRating *root)
{
    if (root == nullptr)
        return root;

    int balanceFactor = getBalanceFactor(root);

    // Left Heavy
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->getLeftChild()) >= 0)
            return rotateRight(root);
        else
        {
            root->setLeftChild(rotateLeft(root->getLeftChild()));
            return rotateRight(root);
        }
    }

    // Right Heavy
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->getRightChild()) <= 0)
            return rotateLeft(root);
        else
        {
            root->setRightChild(rotateRight(root->getRightChild()));
            return rotateLeft(root);
        }
    }

    // No balancing needed
    return root;
}

// Helper function to insert a node into AVL tree
MonthlyRating *ratingAVL::insertHelperAVL(MonthlyRating *root, std::pair<int, int> date, std::vector<int> ratings)
{
   if (root == nullptr)
    {
        MonthlyRating *newNode = new MonthlyRating();
        newNode->set_RatingDates(date.first, date.second);
        newNode->setRatings(ratings);
        return newNode;
    }

    if (*root>date)
    {
        root->setLeftChild(insertHelperAVL(root->getLeftChild(), date, ratings));
    }
    else if (*root<date)
    {
        root->setRightChild(insertHelperAVL(root->getRightChild(), date, ratings));
    }
    root->setHeight(1 + std::max(getHeight(root->getLeftChild()), getHeight(root->getRightChild())));

    return balanceAVL(root);
}

// Helper function to remove a node from AVL tree
MonthlyRating *ratingAVL::removeHelperAVL(MonthlyRating *root, std::pair<int, int> date, std::vector<int> ratings)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (*root>date)
    {
        root->setLeftChild(removeHelperAVL(root->getLeftChild(), date, ratings));
    }
    else if (*root<date)
    {
        root->setRightChild(removeHelperAVL(root->getRightChild(), date, ratings));
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
        root->setRightChild(removeHelperAVL(root->getRightChild(), temp->get_RatingDates(), temp->getRatings()));
    }
    root->setHeight(1 + std::max(getHeight(root->getLeftChild()), getHeight(root->getRightChild())));
    return balanceAVL(root);
}

void ratingAVL::printLevelOrder(MonthlyRating* root) {
    if (!root)
        return;

    // Create a queue for level-order traversal
    std::queue<MonthlyRating*> queue1;

    // Enqueue the root
    queue1.push(root);

    while (!queue1.empty()) {
        // Dequeue a node from the front of the queue
        MonthlyRating* current = queue1.front();
        queue1.pop();

        // Print the dequeued node's value
        current->printAverageMonthlyRating();

        // Enqueue the left child if it exists
        if (current->getLeftChild())
            queue1.push(current->getLeftChild());

        // Enqueue the right child if it exists
        if (current->getRightChild())
            queue1.push(current->getRightChild());
    }
}





















