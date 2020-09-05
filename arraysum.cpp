#include <iostream>
using namespace std;

int main()
{
    int n=7, A[n] = {4,8,6,9,5,2,7}, max;
    max = A[0];

    for(int i=1; i<n; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }

    cout << max << endl;
    return 0;
}