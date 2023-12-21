#include "../Header Files/ratingAVL.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

// Constructors
ratingAVL::ratingAVL()
{
    root = nullptr;
}
ratingAVL::ratingAVL(MonthlyRating &rating) : root(new MonthlyRating(rating)) {}
// Destructor
ratingAVL::~ratingAVL()
{
 
}

// insert functions with different parameters
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
// print in order
void ratingAVL::printAVL(MonthlyRating *root)
{
    printHelper(root);
}
// print level order
void ratingAVL::printLevelOrder(MonthlyRating *root)
{
    if (!root)
        return;

    std::queue<MonthlyRating *> queue1;

    queue1.push(root);

    while (!queue1.empty())
    {
        MonthlyRating *current = queue1.front();
        queue1.pop();
        current->printAverageMonthlyRating();
        if (current->getLeftChild())
            queue1.push(current->getLeftChild());
        if (current->getRightChild())
            queue1.push(current->getRightChild());
    }
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
// functions that will return the average rating of a given date , year ,  period

double ratingAVL::getAverageRatingByMonth(MonthlyRating *root, int month, int year)
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

double ratingAVL::getAverageRatingByMonth(MonthlyRating *root, std::pair<int, int> other)
{

    double ratingInMonth = 0;
    ratingInMonth = getAverageRatingByMonthHelper(root, other);
    return ratingInMonth;
}

double ratingAVL::getAverageratingByYear(MonthlyRating *root, int year)
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

double ratingAVL::getAverageratingByPeriod(MonthlyRating *root, std::pair<int, int> date1, std::pair<int, int> date2)
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

// helper functions
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

    if (*root > date)
    {
        root->setLeftChild(insertHelperAVL(root->getLeftChild(), date, ratings));
    }
    else if (*root < date)
    {
        root->setRightChild(insertHelperAVL(root->getRightChild(), date, ratings));
    }
    else
    {
        std::cerr << "Error: The value " << date.first << " " << date.second << " already exists in the tree. Please provide a unique value." << std::endl;
        return 0;
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
    if (*root > date)
    {
        root->setLeftChild(removeHelperAVL(root->getLeftChild(), date, ratings));
    }
    else if (*root < date)
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
// used by the remove helper when the node have 2 childs
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
// a function that returns the average rating of a given month
double ratingAVL::getAverageRatingByMonthHelper(MonthlyRating *root, std::pair<int, int> other)
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
double ratingAVL::getAverageratingByYearHelper(MonthlyRating *root, int year, int &countMonth, double &tempYear)
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
            std::cerr << "Error: Exception - countMonth should not exceed 12." << std::endl; // the max value that countMonth could take will be 12
            return -1;
        }
        return (countMonth == 0) ? 0.0 : static_cast<double>(tempYear) / static_cast<double>(countMonth);
    }
    else
    {
        return -1;
    }
}
// return the average rating in a given period
double ratingAVL::getAverageratingByPeriodHelper(MonthlyRating *root, std::pair<int, int> firstDate, std::pair<int, int> secondDate)
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
// check if the given date is valid
bool ratingAVL::checkDate(std::pair<int, int> date)
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
// a print in order function
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
//check if the tree is balanced 
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

// the hight function
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
// search to see if a given date is in the tree
bool ratingAVL::DateInBst(MonthlyRating *root, std::pair<int, int> date)
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
// search to see if that given year is in the tree
bool ratingAVL::YearInBst(MonthlyRating *root, int year)
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
