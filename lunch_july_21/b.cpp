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
    ll n;
    cin>>n;
    vll a(n),b(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin>>b[i];
    }
    set<ll> pos;
    for (ll i = 0; i < n; i++) {
        ll z=(a[0]+b[i])%n;
        pos.insert(z);
    }

    auto c=*pos.begin();
    pos.clear();
    for (ll i = 0; i < n; i++) {
        if((a[0]+b[i])%n==c){
            pos.insert(i);
        }
    }

    ll ans=-1;
    c=*pos.begin();
    if(pos.size()==2){
        pos.erase(pos.begin());
        auto d=*pos.begin();
        for (ll i = 0; i < n; i++) {
            ll z=(a[i]+b[(i+c)%n])%n;
            ll w=(a[i]+b[(i+d)%n])%n;
            if(z==w)continue;
            else{
                ans=min(z,w)==z?c:d;
                break;
            }
        }
    }
    if(ans==-1)ans=c;


    for (ll i = 0; i < n; i++) {
        ll z=(a[i]+b[(i+ans)%n])%n;
        cout<<z<<" ";
    }
    cout<<endl;
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








