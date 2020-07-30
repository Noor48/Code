#include <iostream>
#include <cstring>
#include <limits>
#include <cstdio>
using namespace std;

int main()
{
    string messege ("Hello");
    cout << messege << endl;

    cout << "Enter a messege(no space): " << endl;
    cin >> messege;
    cout << messege << endl;

    cin.ignore(numeric_limits<streamsize>::max(),"\n");

    cout << "Enter a messege (with spaces): ";
    getline(cin, messege);
    cout << messege << endl;

    return 0;
}
