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
const ll MOD=1e9+7;
ll binpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
    
}

vector<vll> adj;
vector<bool> vis;
vll lv;
ll e;
ll dfs(ll u,ll lev){
    vis[u]=true;
    lv[u]=lev;
    ll cnt=1;
    for(auto v:adj[u]){
        if(vis[v]){
            if(lv[v]>lev){
                e=lv[v]-lev+1;
            }
            continue;
        }
        cnt+=dfs(v,lev+1);
    }
    return cnt;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    adj=vector<vll>(n);
    vis=vector<bool>(n,false);
    lv=vll(n,0);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin>>x;
        x--;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    
    vector<array<ll,2>> dp(n+1);
    dp[1][0]=0;
    dp[1][1]=m;
    for(ll i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][1]*(m-1)%MOD+dp[i-1][0]*(m-2)%MOD)%MOD;
        dp[i][1]=dp[i-1][0];
    }



    ll ans=1LL;
    for(ll i=0;i<n;i++){
        if(vis[i]){continue;}
        e=0;
        ll cnt=dfs(i,0);
        ll lf=cnt-e;
        ans=ans*binpow(m-1,lf)%MOD;
        ans=ans*dp[e][0]%MOD;
    }

    cout<<ans%MOD<<endl;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 
 
