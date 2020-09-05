#include <iostream>
using namespace std;

int main()
{
    int n=6;
    int A[n] = {2,3,4,5,6,7};

    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;

    for (int x: A)
    {
        cout << x << " ";
    }

    cout << endl;

    for (auto &x : A)
    {
        cout << ++x << " ";
    }

    cout << endl;

    return 0;
}