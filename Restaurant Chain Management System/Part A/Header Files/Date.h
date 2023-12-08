#ifndef DATE_H
#define DATE_H
class Date
{
private:
    int day;
    int month;
    int year;
    bool isValidDay(int, int, int) const;
    bool isValidMonth(int) const;
    bool isValidYear(int) const;
    void validateDate();
    int daysInMonth(int, int) const;
    bool isLeapYear(int) const;

public:
    Date();
    Date(int, int, int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void displayDate() const;
    
    // comparison operators overloading
    bool operator==(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<(const Date &other) const;
};
#endif
