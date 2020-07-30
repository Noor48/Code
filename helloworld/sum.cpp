#include<iostream>
using namespace std;

int main()
{
    int t, n, a;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        a=0;
        cin >> n;

        while(n>0)
        {
            a += n%10;
            n = n/10;
        }
        cout << a << endl;
    }
    return 0;
}
