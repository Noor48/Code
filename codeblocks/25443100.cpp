//
//  Written and Designed by Siddharth
//  siddharthsingh3099@gmail.com
//
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define pb push_back
#define Check cout<<"CHECK"<<endl;
#define ed end()
#define bg begin()
#define sz size()
#define endl "\n"
#define NL cout<<'\n';
#define disp(x) for(int t : x )cout<<t<<" ";
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
int gcd(int a, int b){ if (a == 0) return b; return gcd(b % a, a);}

int32_t main(){
    FASTIO
    int t;cin>>t;
    int p1=0,p2=0;
    int lead=0;
    bool isPlayer1;
    bool p1max;
    while(t--){
        int a,b;
        cin>>a>>b;
        p1+=a;
        p2+=b;
        int test=p1-p2;
        if(test>0){
            isPlayer1=true;
        }else{
            isPlayer1=false;
            test=test*(-1);
        }
        
        if(test>=lead){
            lead=test;
            if(isPlayer1){
                p1max=true;
            }else{
                p1max=false;
            }
        }
    }
    int player;
    if(p1max){
        player=1;
    }else{
        player=2;
    }
    cout<<player<<" "<<lead;
}
