#include<boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
using namespace boost::multiprecision;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       cpp_int ans=1;
       for(int i=1;i<=n;i++)
        ans=ans*i;
       cout<<ans<<"\n";

    }
    return 0;
}

