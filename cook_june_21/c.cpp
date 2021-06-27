#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(),(x).end()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
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
void solve()
{
   ll n;
   cin>>n;
   string s;
   cin>>s;
   ll c0=0;
   ll c1=0;
   for(ll i=0;i<n;i++){
       if(s[i]=='0')c0++;
       else c1++;
   }
   
   if(c1==1){
       cout<<0<<endl;
       return;
   }
   if(c1==0){
       cout<<1<<endl;return;
   }
   if(n&1){
       cout<<min(c0,c1-1)<<endl;return;
   }
   ll ans=INT_MAX;
   ll cnt=0;
   vll v(n/2);
   for(ll i=0;i<n;i++){
       if(s[i]=='1'){
           v[i%(n/2)]++;
       }
   }
//    vll ans(3,INT_MAX);
   ll tmp=0;
//    for(auto &c:v)if(c==1)tmp++,c=0;
   for(ll i=0;i<n/2;i++){
       cout<<i<<" "<<v[i]<<endl;
   }



   
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