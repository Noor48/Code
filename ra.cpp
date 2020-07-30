#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int i=0;
    while(i++<10)
    {
        int r = (rand()%19) + (-9);
        cout << r << " ";
    }

    return 0;
}