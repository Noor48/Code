#include <iostream>
using namespace std;


int main()
{

    float b, a;
    cin >> a >> b;

    if (a<b-0.5)
    {
        if(((int)a%5)==0)
        {
            b = b-a-0.5;

        }else
        b = b;
    }
    cout << b;
        return 0;
}
