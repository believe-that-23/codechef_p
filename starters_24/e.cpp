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


void solve()
{
    ll n,mm;
    cin>>n;
    string s;
    cin>>s;
    cin>>mm;
    map<ll,ll> m;
    for (ll i = 0; i < 26; i++) {
        m[i]=n;
    }
    vll a(n);
    for(ll i=n-1;i>=0;i--){
        ll z=s[i]-'a';
        ll pos=m[(z+1)%26];
        a[i]=pos;
        m[z]=i;
    }

    ll limit=log2(mm)+1;

    vector<vll> dp(n+1,vll(limit+1,n));
    for(ll i=0;i<n;i++){
        dp[i][0]=a[i];
    }
    for(ll i=1;i<=limit;i++){
        for(ll j=0;j<n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }

//    for (ll i = 0; i < n; i++) {
//        for (ll j = 0; j < limit; j++) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    ll ans=INT_MAX;
    for(ll i=0;i<n;i++){

        if(s[i]!='a')continue;

        ll k=mm-1;
        ll st=i;
        for(ll j=limit;j>=0;j--){
            if(k-(1LL<<j)>=0){
                k-=(1LL<<j);
                st=dp[st][j];
            }
        }
        if(st!=n){
            ans=min(ans,st-i+1-mm);
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else
        cout<<ans<<endl;

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








