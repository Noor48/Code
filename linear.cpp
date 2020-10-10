#include <iostream>
using namespace std;

int main()
{
    int n=10, A[n], key;

    cout << "Enter numbers: ";
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter Key: ";
    cin >> key;

    for(int i=0; i<n; i++)
    {
        if (key==A[i])
        {
            cout << "found at " << i  << endl;

            return 0;
        }
    }

    cout << "didn; find the key" << endl;

    return 0;
}