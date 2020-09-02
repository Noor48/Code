#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, r, rev=0, m, r1, rev1=0;
    cout << "Enter number: ";
    cin >> n;
    m=n;

    while(n>0)
    {
        r=n%10;
        n=n/10;
        rev = rev*10 + r;
    }

    cout << "Reverse of the number: " << rev << endl;

    if(m==rev)
    {
        cout << "It is a palindrome number." << endl;
    }

    else
    {
        cout << "Not a palidrome number. " << endl;
    }

    while(rev>0)
    {
        r1=rev%10;
        rev=rev/10;
        rev1 = rev1*10 + r1;

        switch(r1)
        {
            case 1 : cout << "one ";
                break;
            case 2 : cout << "two ";
                break;
            case 3 : cout << "three ";
                break;
            case 4 : cout << "four ";
                break;
            case 5 : cout << "five ";
                break;
            case 6 : cout << "six ";
                break;
            case 7 : cout << "seven ";
                break;
            case 8 : cout << "eight ";
                break;
            case 9 : cout << "nine ";
                break;
                
        }
    }

    cout << endl <<  rev1 << endl;
    
    return 0;
}