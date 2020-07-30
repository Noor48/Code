#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int Mat1[10][10];
    int Mat2[10][10];
    int Mat3[10][10];
    Back1:
    cout << endl << "Enter the number of rows in Matrix 1 : ";
    cin >> a;
    cout << endl << "Enter the number of columns in Matrix 1 : ";
    cin >> b;
    cout << endl << "Enter the number of rows in Matrix 2 : ";
    cin >> c;
    cout << endl << "Enter the number of column in Matrix 2 : ";
    cin >> d;
    if (b != c) {
        cout << endl << "******************************************"
             << "\nThis type of Matrix can't be multiplied . " << endl;
        goto Back1;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << endl << "(MAT 1 ) \n\nEnter the Element of row " << i + 1
                 << " column " << j + 1 << " : ";
            cin >> Mat1[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            cout << endl << "(MAT 2 ) \n\nEnter the Element of row " << i + 1
                 << " column " << j + 1 << " : ";
            cin >> Mat2[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            Mat3[i][j] = Mat1[i][j] * Mat1[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            cout << Mat3[i][j];
        }
        cout << endl;
    }
}


