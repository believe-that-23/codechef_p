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
void solve()
{
   ll x,y;
   cin>>x>>y;
   ll ans=0;
   ll streak;
   map<ll,ll> m;
   while(x<=y){
       streak=0;
       ll z=x;
      while(z<=y){
          y-=z;
          z*=2;
          streak++;
          ans++;
      }
      m[streak]++;
      if(y==0)continue; 
      ans++;
   }
   for(auto c:m){
       if(c.se>1){
           cout<<-1<<endl;
           return;
       }
   }
   if(y==0){
       cout<<ans<<endl;
   }
   else{
       cout<<-1<<endl;
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