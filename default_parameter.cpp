#include <iostream>
using namespace std;

int sum(int a, int b, int c=0)
{
    return a+b+c;
}

int max(int a, int b, int c)
{
    return a>b && a>c ?a : (b>c ? b : c);
}
int main()
{
    cout << sum(10,5) << endl;
    cout << sum(10,5,8) << endl;
    cout << max(30, 10) << endl;

    return 0;
}