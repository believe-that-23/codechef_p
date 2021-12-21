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
ll timer=1;
vll in(100005);
vll out(100005);
vll flat_tree(200005);
vll adj[100005];
vll a;
vll g(100005);
vll parent(100005);

void dfs(ll u,ll p){
    parent[u]=p;
    in[u]=timer;
    flat_tree[timer]=u;
    timer++;
    g[u]=a[u];
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        g[u]=__gcd(g[u],g[v]);
    }
    flat_tree[timer]=u;
    out[u]=timer;
    timer++;
}

void solve()
{
    ll n;
    cin>>n;

    a.assign(n+1,0);
    parent.clear();
    flat_tree.clear();
    in.clear();
    out.clear();
    g.clear();
    for(ll i=1;i<100005;i++){
        adj[i].clear();
    }

    for (ll i = 0; i < n-1; i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (ll i = 1; i <= n; i++) {
        cin>>a[i];
    }
    timer=1;
    dfs(1,-1);
    ll si=2*n;
    vll pref(si+1);
    vll suff(si+1);
    pref[1]=suff[si]=a[1];
    for(ll i=2;i<=si;i++){
        pref[i]=__gcd(pref[i-1],a[flat_tree[i]]);
    }

    for(ll i=si-1;i>=1;i--){
        suff[i]=__gcd(suff[i+1],a[flat_tree[i]]);
    }
    ll ans=1;
    ll temp;
    for(ll i=1;i<=n;i++){
        vll child;
        for(auto v:adj[i]){
            if(v!=parent[i]){
                child.pb(g[v]);
            }
        }
        if(child.size()!=0){
            temp=0;
            for(ll c:child){
                temp+=c;
            }
            ll tmp;
            if(i!=1){
                tmp=__gcd(pref[in[i]-1],suff[out[i]+1]);
                ans=max(ans,temp+tmp);
            }else{
                ans=max(ans,temp);
            }
        }
        else{
            temp=__gcd(pref[in[i]-1],suff[out[i]+1]);
            ans=max(ans,temp);
        }
    }
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








