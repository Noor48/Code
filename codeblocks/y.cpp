#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, num, count;
    cin >> a >> b;

    for (int num=a; num<=b; num++)
    {
        count = 0;
        for (int i=2; i<=sqrt(num); i++)
        {
            if (num%i == 0)
            {
                count++;
                break;
            }
        }

        if(count ==0 && num != 1)
        {
            cout << num << endl;
        }
    }

    return 0;
}
