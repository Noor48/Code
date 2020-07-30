#include <iostream>
using namespace std;

int main()
{
    int m1[5][5], m2[5][5], m[5][5]={0}, a, b, c, d;

    cout << "Enter rows and columns for the first matrix: " << endl;
    cin >> a >> b;
    cout << "Enter rows and columns for the second matrix: " << endl;
    cin >> c >> d;

    while(b!=c)
    {
        cout << "These matrix can't be multiplied" << endl;

        cout << "Enter rows and columns for the first matrix: ";
        cin >> a >> b;

        cout << "Enter rows and columns for the second matrix: ";
        cin >> c >> d;
    }

    cout << "Enter first matrix: " << endl;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            cin >> m1[i][j];
        }
    }
    cout << "Enter socond matrix: " << endl;
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<d; j++)
        {
            cin >> m2[i][j];
        }
    }

    for(int i=0; i<a; i++)
    {
        for(int j=0; j<d; j++)
        {
            for(int k=0; k<b; k++)
            {
                m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }


    cout << "The multiplication is:" << endl;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<d; j++)
        {
            cout <<  m[i][j] << " ";
        }

        cout << endl;
    }

    return 0;

}
