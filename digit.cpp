#include <iostream>
using namespace std;

int main()
{
    int n,r;
    cout << "Enter your number: ";
    cin >> n;

    while(n>0)
    {
        r=n%10;
        n=n/10;

        cout << r << " ";
    }

    cout << endl;
    return 0;
}