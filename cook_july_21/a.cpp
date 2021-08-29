#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
#define endl "\n"
ll C(ll n, ll k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
       res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<vll> readGraph(ll n,ll m){
    vector<vll> g(n);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        //sc.read(a,b);
        //a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return g;
}
vector<vll> readTree(int n){
    return readGraph(n,n-1);
}
//----------------------------------------------------------------------------
bool is_prime(ll n){
    if(n==1||n==2){
        return true;
    }
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
void solve()
{
   ll x,y;
   cin>>x>>y;
   if(__gcd(x,y)!=1){
       cout<<0<<endl;
       return;
   }
   ll ans;
   ll cnt=0;

   if(x<y)swap(x,y);
   if(x%2==1&&y%2==1){
       if(__gcd(x+1,y)!=1||__gcd(x,y+1)!=1)ans=1;
       else ans=2;
   }
   if(x%2==0||y%2==0)ans=1;

   cout<<ans<<endl;
}
int main() {
FAST;
ll t;
cin>>t;
while(t--){
   solve();
}
return 0;
}








