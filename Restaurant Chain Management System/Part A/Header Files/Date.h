
class Date {
private:
    int day;
    int month;
    int year;
public:
Date();
Date(int,int,int);
int getDay() const;
int getMonth() const;
int getYear() const;
void setDay(int);
void setMonth(int);
void setYear(int);
void displayDate() const;
};