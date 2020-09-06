#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "Enter year: ";
    cin >> i;

    if(i%4==0)
    {
        if(i%100==0)
        {
            if(i%400==0)
            {
                cout << i << " is a leap year." << endl;
            }

            else 
            {
                cout << i << " is not a leap year." << endl;
            }
        }

        else 
        {
            cout << i << " is a leap year." << endl;
        }
    }

    else 
    {
        cout << i << " is not a leap year." << endl;
    }

    return 0;
}