#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<=t; i++)
    {
    int a, b;
    cin >> a >> b;

         for (int j=1; j<=a; j++)
         {
             for (int k=1; k<=b; k++)
             {
                 if ((j+k)%2==0)
                 {
                     cout << "*";
                 }
                 else
                    cout << ".";
             }
             cout << endl;
         }

    }
}
