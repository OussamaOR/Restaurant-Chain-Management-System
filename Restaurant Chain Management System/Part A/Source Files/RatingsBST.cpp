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
//functions that will return the average rating of a given date , year ,  period 

double ratingsBST::getAverageRatingByMonth(MonthlyRating *root, int month, int year)
{
    double ratingInMonth = 0;
    std::pair<int, int> temp = std::make_pair(month, year);
    ratingInMonth = getAverageRatingByMonthHelper(root, temp);
    if (ratingInMonth == -1)
    {
        std::cerr << "Error: The specified date does not exist." << std::endl;
    }
    else
    {
        if (ratingInMonth == -2)
        {
            std::cerr << "Error: Invalid date provided. Please enter a valid date." << std::endl;
        }
        else
        {
            if (ratingInMonth == -3)
            {
                std::cerr << "Error: The date is not present in the tree. Unable to retrieve a rating." << std::endl;
            }
            else
            {
                return ratingInMonth;
            }
        }
    }
}

double ratingsBST::getAverageRatingByMonth(MonthlyRating *root, std::pair<int, int> other)
{
    double ratingInMonth = 0;
    ratingInMonth = getAverageRatingByMonthHelper(root, other);
    return ratingInMonth;
}

double ratingsBST::getAverageratingByYear(MonthlyRating *root, int year)
{
    int countMonth = 0;
    double tempYear = 0;
    double averageYear = getAverageratingByYearHelper(root, year, countMonth, tempYear);
    if (averageYear == -1)
    {
        std::cerr << "Error: The tree is empty. Unable to calculate average for the specified year." << std::endl;
    }
    else
    {
        if (averageYear == -2)
        {
            std::cerr << "Error: Invalid year provided. Please enter a valid year for average calculation." << std::endl;
        }
        else
        {
            if (averageYear == -3)
            {
                std::cerr << "Error: The specified year is not present in the tree. Unable to calculate average." << std::endl;
            }
            else
            {
                return averageYear;
            }
        }
    }
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
        std::cerr << "Error: The specified date does not exist in the tree." << std::endl;
    }
    else
    {
        if (periodRating == -2)
        {
            std::cerr << "Error: Invalid date provided. Please enter valid dates for rating calculation." << std::endl;
        }
        else
        {
            if (periodRating == -3)
            {
                std::cerr << "Error: One or more dates are not present in the tree. Unable to calculate rating for the given period." << std::endl;
            }
            else
            {
                return periodRating;
            }
        }
    }
}

// helper functions:
// a helper to insert in the tree
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
    else
    {
        std::cerr << "Error: The value " << date.first << " " << date.second << " already exists in the tree. Please provide a unique value." << std::endl;
    }

    return root;
}
// a helper to remove  an element from the tree
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
// used by the remove helper when the node have 2 childs
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
// a print in order function
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
// a function that returns the average rating of a given month
double ratingsBST::getAverageRatingByMonthHelper(MonthlyRating *root, std::pair<int, int> other)
{
    double aveRating = 0;
    if (!(DateInBst(root, other)))
    {
        return -3; // the date is not in the tree
    }
    if (!(checkDate(other)))
    {
        return -2; // provided date not valid
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
// return the average rating of in a year
double ratingsBST::getAverageratingByYearHelper(MonthlyRating *root, int year, int &countMonth, double &tempYear)
{
    if (!YearInBst(root, year))
    {
        return -3;
    }
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
        if (countMonth > 12)
        {
            std::cerr << "Error: Exception - countMonth should not exceed 12." << std::endl;//the max value that countMonth could take will be 12
        }
        return (countMonth == 0) ? 0.0 : static_cast<double>(tempYear) / static_cast<double>(countMonth);
    }
    else
    {
        return -1;
    }
}
//return the average rating in a given period 
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
    if (!(DateInBst(root, firstDate) && DateInBst(root, secondDate)))
    {
        return -3;
    }
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
        }

        current = current->getRightChild();
    }
    return (countPeriod == 0) ? 0.0 : static_cast<double>(tempPeriod) / static_cast<double>(countPeriod);
}
//check if the given date is valid 
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
//search to see if a given date is in the tree 
bool ratingsBST::DateInBst(MonthlyRating *root, std::pair<int, int> date)
{
    if (root == NULL)
    {
        return false;
    }

    if (*root == date)
    {
        return true;
    }

    if (*root > date)
    {
        return DateInBst(root->getLeftChild(), date);
    }

    return DateInBst(root->getRightChild(), date);
}
//search to see if that given year is in the tree 
bool ratingsBST::YearInBst(MonthlyRating *root, int year)
{
    if (root == NULL)
    {
        return false;
    }

    if ((root->get_RatingDates()).second == year)
    {
        return true;
    }

    if ((root->get_RatingDates()).second > year)
    {
        return YearInBst(root->getLeftChild(), year);
    }

    return YearInBst(root->getRightChild(), year);
}
