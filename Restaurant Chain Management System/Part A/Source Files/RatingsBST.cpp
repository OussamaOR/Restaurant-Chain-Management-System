#include "RatingsBST.h"
#include <iostream>
#include <stack>
// Constructors
ratingsBST::ratingsBST()
{
    root = nullptr;
}
ratingsBST::ratingsBST(MonthlyRating &rating) : root(new MonthlyRating(rating)) {}
// Destructor
ratingsBST::~ratingsBST() { makeEmpty(root); }

// insert functions with different parameters
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
    root = nullptr;
    return true;
}
double ratingsBST::getAverageRatingByMonth(MonthlyRating *root, int month, int year)
{
    double ratingInMonth = 0;
    std::pair<int, int> temp = std::make_pair(month, year);
    ratingInMonth = getAverageRatingByMonthHelper(root, temp);
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
double ratingsBST::getAverageRatingByMonth(MonthlyRating *root, std::pair<int, int> other)
{

    double ratingInMonth = 0;
    ratingInMonth = getAverageRatingByMonthHelper(root, other);
    return ratingInMonth;
}
double ratingsBST::getAverageratingByPeriod(MonthlyRating *root, std::pair<int, int> date1, std::pair<int, int> date2)
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
double ratingsBST::getAverageratingByYear(MonthlyRating *root, int year)
{
    int countMonth = 0;
    double tempYear = 0;
    double averageYear = getAverageratingByYearHelper(root, year, countMonth, tempYear);
    if (averageYear == -1)
    {
        std::cerr << "empty tree  " << std::endl;
    }
    else
    {
        if (averageYear == -2)
        {
            std::cerr << "invalid year provided  " << std::endl;
        }
        else
        {
            return averageYear;
        }
    }
}
// helper functions
MonthlyRating *ratingsBST::insertHelper(MonthlyRating *root, std::pair<int, int> date, std::vector<int> ratings)
{
    if (root == nullptr)
    {
        MonthlyRating *newNode = new MonthlyRating();
        newNode->set_RatingDates(date.first, date.second);
        newNode->setRatings(ratings);
        return newNode;
    }

    if (*root > date)
    {
        root->setLeftChild(insertHelper(root->getLeftChild(), date, ratings));
    }
    else if (*root < date)
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
    if (*root > date)
    {
        root->setLeftChild(removeHelper(root->getLeftChild(), date, ratings));
    }
    else if (*root < date)
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
double ratingsBST::getAverageRatingByMonthHelper(MonthlyRating *root, std::pair<int, int> other)
{
    double aveRating = 0;

    if (!(checkDate(other)))
    {
        return -2;
    }
    if (!root)
    {
        return -1;
    }
    if (root)
    {
        if ((root->get_RatingDates()).first == other.first && (root->get_RatingDates()).second == other.second)
        {
            aveRating = root->averageRating();
            return aveRating;
        }
        else
        {
            if ((root->get_RatingDates()).first < other.first || ((root->get_RatingDates()).first == other.first && (root->get_RatingDates()).second < other.second))
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
bool ratingsBST::checkDate(std::pair<int, int> date)
{

    if (date.second <= 1999)
    {
        return false;
    }
    else
    {
        if (date.first < 1 && date.first >= 13)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
double ratingsBST::getAverageratingByPeriodHelper(MonthlyRating *root, std::pair<int, int> firstDate, std::pair<int, int> secondDate)
{
    int countPeriod = 0;
    double tempPeriod = 0;
    if (!(checkDate(firstDate) && checkDate(secondDate)))
    {
        return -2;
    }
    if (root == nullptr)
    {
        return -1;
    }
    bool foundMatchingNode = false;

    std::stack<MonthlyRating *> stack;
    MonthlyRating *current = root;

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
double ratingsBST::getAverageratingByYearHelper(MonthlyRating *root, int year, int &countMonth, double &tempYear)
{
    if (year < 2000)
    {
        return -2;
    }
    if (root)
    {
        if (root->get_RatingDates().second == year)
        {
            tempYear += root->averageRating();
            countMonth++;
        }

        getAverageratingByYearHelper(root->getLeftChild(), year, countMonth, tempYear);
        getAverageratingByYearHelper(root->getRightChild(), year, countMonth, tempYear);

        return (countMonth == 0) ? 0.0 : static_cast<double>(tempYear) / static_cast<double>(countMonth);
    }
    else
    {
        return -1;
    }
}