#include<iostream>
using namespace std;

int main()
{
    int x = 3, y = 4;
    x=y;
    cout << x << endl;
    x =y++;
    cout << x << endl;
    cout << y << endl;
    y = ++x;
    cout << x << endl;
    cout << y << endl;
    return 0;
}
