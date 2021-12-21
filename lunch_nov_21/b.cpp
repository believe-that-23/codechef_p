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


void solve()
{
    ll n;
    cin>>n;
    n*=2;
    vll a(n);
    map<ll,ll> m; 
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        m[a[i]]++;
    }
    vll b=a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    vll c;
    ll cnt=1;
    ll ele=0;
    for(ll i=0;i<b.size();i++){
        c.pb(b[ele]);
        cnt++;
        if(cnt&1){
            ele++;
        }
    }
    c.pb(b.back());
    ele=b.size()-2;
    cnt=1;
    for(ll i=b.size()-2;i>=0;i--){
        c.pb(b[ele]);
        cnt++;
        if(cnt&1){
            ele--;
        }
    }
    sort(all(a));
    sort(all(c));
    if(a==c){
        for(auto x:b)cout<<x<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
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








