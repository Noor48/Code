#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a positive integer: ";
    int l;
    cin >> l;

    int *array = new int [l] ;
    cout << "Enter array values: " << endl;
    for (int i = 0; i < l; i++)
    {
        cin >> array[i];
    }

    cout << "Size of array: " << l << endl;
    cout << "You entered: ";
    for (int i = 0; i < l; i++)
    {
        cout << array[i] << " ";
    }
     delete[] array;
     return 0;
}
