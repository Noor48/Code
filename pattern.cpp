#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,count=1;
    cout << "Enter number: ";
    cin >> n;

    for(int i=0; i<sqrt(n); i++)
    {
        for(int j=0; j<sqrt(n); j++)
        {
            cout << count << " ";
            count++;
        }

        cout << endl;
    }

    return 0;
}