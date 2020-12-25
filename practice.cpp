#include <iostream>
using namespace std;

int search(int A[], int key, int n)
{
    for(int i=0; i<n;i ++)
    {
        if(key==A[i])
        {
            return i;

            return 0;
        }

    }
}

int main()
{
    int A[] = {2,4,5,7,10,9,13};

    int k;
    cout << "Enter an element to be searched: ";
    cin >> k;
    int index = search(A,7,k);
    cout << "Element found at: " << index << endl;
}