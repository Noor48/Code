#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int i=0;
    srand(time(NULL));
    while (i++<10)
    {
        int r = (rand()%100) + 1;

        cout << r << "  ";
    }

    return 0;
}