#include <iostream>
using namespace std;

int main()
{
    int n,sum=0, avg;
    cout << "Enter numbers of element: ";
    cin >> n;
    float arr[n]={};
    cout << "Enter numbers: ";

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    avg = sum/n;

    cout << avg << endl;

    return 0;
}