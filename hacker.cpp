#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i1 = 12;
    double d1 = 4;
    string s1 = " is the best place to learn and practice coding";

    int i2;
    double d2;
    string s2;
    
    cin >> i2;
    cin >> d2;
    getline(cin>>ws, s2);

    cout << i1 + i2 << endl;
    cout << d1 + d2 << endl;
    cout << s2 + s1 << endl;
    return 0;
}