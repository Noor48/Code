#ifndef Bir_h
#define Bir_h
#include <iostream>
using namespace std;

class Birthday
{
    public:
    Birthday(int m, int d, int y)
    : month(m), day(d), year(y)
    {}

    void printdate()
    {
        cout << month << "/" << day << "/" << year << endl;
    }

    private:

    int month;
    int day;
    int year;
};

#endif // Bir_h