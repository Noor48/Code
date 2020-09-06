#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double mealCost; 
    int tipPercent, taxPercent;
    cin >> mealCost >> tipPercent >> taxPercent;
 
    double tip = mealCost * tipPercent/100; 
    double tax =  mealCost * taxPercent/100;

    int total = round(mealCost + tip + tax);

    cout << total << endl;

    return 0;
}