#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long n, ans = 0;
        cin >> n;

        while(n)
        {
            ans = ans*10 + n%10;
            n /= 10;
        }

        cout << ans << endl;
    }   

    return 0;
}
