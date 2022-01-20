#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define eb emplace_back
#define mp make_pair
#define ll long long
#define lld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;
using namespace __gnu_pbds;
//#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>

//-----------------------------------------------------------

ll n;
string s,t;
vll ps,pt;
vector<vll> dp(1005,vll(1005));
ll solve(ll i,ll j){
    if(i<0){
        ll temp=0;
        for(ll k=j;k>=0;k--){
            if(t[k]=='1')temp+=ps[0]+pt[k];
        }
        return temp;
    }
    if(j<0){
        ll temp=0;
        for(ll k=i;k>=0;k--){
            if(s[k]=='1')temp+=pt[0]+ps[k];
        }
        return temp;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll val=solve(i-1,j)+(s[i]=='1'?ps[i]+pt[j+1]:0);
    val=min(val,solve(i,j-1)+(t[j]=='1'?ps[i+1]+pt[j]:0));
    return dp[i][j]=val; 
}

void solve()
{
    for (ll i = 0; i < 1005; i++) {
        for (ll j = 0; j < 1005; j++) {
            dp[i][j]=-1;
        }
    }
    cin>>n;
    cin>>s>>t;
    ps.assign(n+1,0);
    pt.assign(n+1,0);
    if(s[n-1]=='0')ps[n-1]++;
    if(t[n-1]=='0')pt[n-1]++;
    for(ll i=n-2;i>=0;i--){
        ps[i]+=ps[i+1];
        if(s[i]=='0')ps[i]++;
    }
    for(ll i=n-2;i>=0;i--){
        pt[i]+=pt[i+1];
        if(t[i]=='0')pt[i]++;
    }
    cout<<solve(n-1,n-1)<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}








