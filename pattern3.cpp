#include <iostream>
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
            if(i+j>=n-1)
            {
                cout <<"*";
            }

            else
            {
                cout << " ";
            }
        }

        for(int j=1; j<n; j++)
        {
            if(i>=j)
            {
                cout << "*";
            }
        }

        cout << endl;
    }

    cout << endl;

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j)
            {
                cout<< " ";
            }

            else
            {
                cout << "*";
            }
        }

        for(int j=1; j<n; j++)
        {
            if(i+j<=n-1)
            {
                cout<< "*";
            }

            else 
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    cout << endl;

    int count;

    for(int i=0; i<n; i++)
    {
        count = 1;
        for(int j=0; j<n; j++)
        {
            if(i>=j)
            {
                cout << count;
            }
        }

        cout << endl;
    }

}