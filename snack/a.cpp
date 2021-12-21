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
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    function<ll(ll,ll,ll)> f=[&](ll i,ll j,ll k){
        ll temp=(a[i]-a[j])*(a[j]-a[k]);
        return temp;
    };
    ll ans=0;
    for (ll i = 0; i < n; i++) {
        set<ll> s;
        for(ll j=i;j<n;j++){
            s.insert(a[j]);
            if(j-i<2)continue;
            ll temp=0;
            auto l=s.lower_bound((a[i]+a[j])/2);
            if(l!=s.end()){
                temp=(a[i]-(*l))*((*l)-a[j]);
            }
            if(l!=s.begin()){
                l--;
                temp=max(temp,(a[i]-(*l))*((*l)-a[j]));
            }
            ans+=temp;
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








