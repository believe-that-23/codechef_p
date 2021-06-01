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
   ll n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   if(n==1){
       while(k--){ll u;cin>>u;cout<<0<<endl;}
       return;
   }
   ll ans=0;
   for(ll i=0;i<n-1;i++){
       ans+=(s[i]==s[i+1]?2:1);
   }
   while(k--){
       ll u;
       cin>>u;
       u--;
       
       if(u>0&&u<n-1){
           ans-=(s[u]==s[u+1]?2:1);
           ans-=(s[u]==s[u-1]?2:1);
           ll z=0;
           if(s[u]=='1')s[u]='0';
           else s[u]='1';
           if(s[u-1]==s[u])z+=2;
           else z+=1;
           if(s[u]==s[u+1])z+=2;
           else z+=1;
           ans+=z;
           cout<<ans<<endl;
           continue;
       }
       else if(u==0){
           ans-=(s[u]==s[u+1]?2:1);
           if(s[u]=='1')s[u]='0';
           else s[u]='1';
           if(s[u]==s[u+1])ans+=2;
           else ans+=1;
           cout<<ans<<endl;
           continue;
       }
       else{
           ans-=(s[u]==s[u-1]?2:1);
           if(s[u]=='1')s[u]='0';
           else s[u]='1';
           if(s[u]==s[u-1])ans+=2;
           else ans+=1;
           cout<<ans<<endl;
           continue;
       }

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