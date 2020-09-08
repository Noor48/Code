#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter row number: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>=j)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n-i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j)
            {
                cout << " ";
            }

            else 
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j)
            {
                cout << " ";
            }

            else 
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    cout << endl;
    
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j<=n-i)
            {
                cout << " ";
            }

            else
            {
                cout << "*";
            }
        }

        cout << endl;
    }

    cout << endl;
    
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j<=n-i)
            {
                cout << " ";
            }

            else
            {
                cout << "* ";
            }
        }

        cout << endl;
    }

    return 0;
}