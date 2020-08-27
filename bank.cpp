#include <iostream>
using namespace std;

int main()
{
    double b, r;
    int d;
    cout << "Enter bill amount: " << endl;
    cin >> b;
    
    if (b>=100 && b<500)
    {
        r = b*10/100;
    }

    else if (b>=500)
    {
        r = b*20/100;
    }

    cout << "bill amount is: " << b << endl;
    cout << "discount amount is: " << r << endl;
    cout << "discounted amount is: " << b-r << endl;
    
    return 0;
}