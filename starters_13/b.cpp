#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;

//-----------------------------------------------------------


void solve()
{
    ll p,a,b,c,x,y;
    cin>>p>>a>>b>>c>>x>>y;
    ll w=a*x+b;
    ll z=a*y+c;
    if(w<z){
        cout<<p/w<<endl;
    }
    else cout<<p/z<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








