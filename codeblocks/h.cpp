#include <iostream>
using namespace std;

int main()
{
    ineligible:
        cout << "Your are not eligible to vote" << endl;
        cout << "Enter your age" << endl;
        int age;
        cin >> age;
        if (age <18)
        {
            goto ineligible;
        }

        else
        {
            cout << "Your are eligible to vote" << endl;
        }

        return 0;
}
