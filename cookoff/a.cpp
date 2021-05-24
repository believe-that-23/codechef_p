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
vector<vll> grid(2000,vll(2000));
void solve()
{
   ll x1,x2,y1,y2;
   cin>>x1>>y1>>x2>>y2;
   x1--,y1--,x2--,y2--;
   ll k=1;
   
//    cout<<"yes";
   
//    grid[0][0]=1;
   
//    cout<<grid[1][0];
//    for(ll i=0;i<1000;i++){
//        for(ll j=0;j<1000;j++){
//            cout<<grid[i][j]<<" ";
//        }
//        cout<<endl;
//    }
   ll ans=0;
   bool flag=false;
   for(ll i=x1;i<=x2;i++){
    //    cout<<grid[i][y1]<<" ";
       ans+=grid[i][y1];
       flag=true;
   }
   for(ll i=y1+flag;i<=y2;i++){
    //    cout<<grid[x2][i]<<" ";
       ans+=grid[x2][i];
   }
   cout<<ans<<endl;
   

}
int main() {

FAST;
ll z=1;
for(ll i=0;i<2000;i++){
       ll m=i;
       ll j=0;
       grid[j][m]=z++;
       while(true){
           j++;m--;
           if(j==2000||m<0)break;
           grid[j][m]=z++;
        //    m++;
       }
   }
ll t;
cin>>t;
while(t--){
   solve();
}
return 0;
}