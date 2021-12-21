#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define lld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>

//-----------------------------------------------------------

vll adj[100005];
vll a;
ll ans=INT_MIN;
vll g;

void dfs(ll u,ll p){
    g[u]=a[u];
    for(auto v:adj[u]){
        if(v==p){
            continue;
        }

        dfs(v,u);
        g[u]=__gcd(g[u],g[v]);
    }
}
void dfs1(ll u, ll p,ll e){
    ll temp = e;
    for(auto v:adj[u]){
        if(v==p)continue;
        temp+=g[v];
    }
    ans=max(ans,temp);
    ll trans=__gcd(a[u],e);
    ll n = adj[u].size();
    if(p!=-1){
        n--;
    }
    vector<ll> pref(n+2,trans),suff(n+2,trans);
    ll id=0;
    for(auto v:adj[u]){
        if(v == p) continue;
        id++;
        pref[id]=__gcd(pref[id],g[v]);
        suff[id]=__gcd(suff[id],g[v]);
    }
    for(ll i=1;i<=n;i++){
        pref[i] = __gcd(pref[i],pref[i-1]);
    }
    for(ll i=n;i>=1;i--){
        suff[i]=__gcd(suff[i],suff[i+1]);
    }
    id=0;
    for(auto v:adj[u]){
        if(v==p)continue;
        id++;
        ll comb= __gcd(pref[id-1], suff[id+1]);
        dfs1(v,u,comb);
    }
}

void solve()
{
    for (ll i = 0; i < 100005; i++) {
        adj[i].clear();
    }
    g.clear();
    a.clear();
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    a.assign(n,0);
    g.assign(n,0);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ans=INT_MIN;
    dfs(0,-1);
    dfs1(0,-1,0);
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    cin>>t;
    for(ll i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}








