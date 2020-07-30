#include <iostream>
#include <string>
using namespace std;

char* c = "a";

int main()
{
    char* c = "b";
    cout << "Local variable: " << c << "\n";
    cout << "Global variable: " << ::c << "\n";

    return 0;
}
