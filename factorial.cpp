#include<boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
using namespace boost::multiprecision;
using namespace std;

int main() {
	int t, n, i;
	cpp_int fact;
	cin>>t;
	for(i=0; i<t; i++){
	    cin>>n;
	    fact=1;
	    for(int j=2; j<=n; j++){
	        fact=fact*j;
	    }
	    cout<<fact<<endl;
	}
	return 0;
}

