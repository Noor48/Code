//DEEPANSHU SAXENA(saxenad765)
#include <bits/stdc++.h>
#define ll long long
#define array(x,n) (x,x+n)
#define all(c) (c).begin(),(c).end()
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define DEBUG(str) cout << "----------" << #str << ':' << str <<"----------" << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
using lf=long double;
#define op(x) cout<<x<<endl
#define F first
#define S second
#define ops(x) cout<<x<<" "
#define odd(x) (x&1)
#define even(x) (!x&1)
#define cpresent(a,x) (find(all(a),x) != (a).end())
#define it(a,i) for(typeof((a).begin() i = (a).begin(); i != (a).end(); i++)
#define present(a,x) ((a).find(x) != (a).end())
#define fbei(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fbe(i,x,y) for(ll i=x;i<=y;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GCD(x,y) __gcd(x,y)
using namespace std;
//using codechef ide;
//Deepanshu Saxena
inline void filehandling()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
vector<ll> vector_in(ll n)
{
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	cin>>v[i];
	return v;
}
void vector_out(vector<ll> v)
{
	for(ll i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
}
ll vector_sum(vector<ll> v)
{
	ll sum;
	for(ll i=0;i<v.size();i++)
	sum+=v[i];
	return sum;
}
int main()
{
	fast
	filehandling();
	ll testcase=1;
	// ip(testcase);
	while(testcase--)
	{
		ll n,z=0,maxf=LLONG_MIN,maxs=LLONG_MIN,f=0,s=0;
		ip(n);
		ll arr1[n];
		ll arr2[n];
		for(ll i = 0;i < n;i++){
		    cin >> arr1[i];
		    cin >> arr2[i];
		}
		for(ll i = 1; i < n; i++){
		    arr1[i] = arr1[i] + arr1[i-1];
		    arr2[i] = arr2[i] + arr2[i-1];
		}
		ll min = abs(arr1[0] - arr2[0]);
		ll j = 0;
		fbe(i,1,n-1)
		{
		    if(abs(arr1[i]-arr2[i]) > min)
		    {
		        min = abs(arr1[i] - arr2[i]);
		        j = i;
		    }
		}
		if(arr1[j] > arr2[j])
		    cout << 1 <<" "<< min << endl;
		else
		    cout << 2 <<" "<< min << endl;
	}
}


