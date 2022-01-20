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
#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>

//-----------------------------------------------------------


void solve()
{
    ll n;
    cin>>n;
    vll a(n);
    map<ll,ll> m;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        m[a[i]]=i;
    }
    vll b=a;
    sort(all(b));
    ll l=-1,r=-1;
    for (ll i = 0; i < n; i++) {
        if(a[i]!=b[i]){
            l=i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(a[i]!=b[i]){
            r=i;
            break;
        }
    }
    if(l==-1){
        cout<<0<<endl;
        return;
    }
    ll mi=INT64_MAX;
    ll mx=0;
    for (ll i = l; i <= r; i++) {
        mi=min(mi,a[i]);
        mx=max(mx,a[i]);
    }
    cout<<mx-mi<<endl;
//    if(is_sorted(all(a))){
//        cout<<0<<endl;
//        return;
//    }
//    map<ll,ll> mm;
//    for(ll i=n-1;i>=0;i--){
//        mm[a[i]]=i;
//    }
//    ll z=*max_element(all(a));
//    ll y=*min_element(all(a));
//    ll ans=z-y;
//    if(mm[z]>m[y]){
//        ll mx=0;
//        ll mi=INT64_MAX;
//        for(ll i=0;i<m[y];i++){
//            mx=max(a[i],mx);
//        }
//        ll p=mx-y;
//        for(ll i=mm[z];i<n;i++){
//            mi=min(mi,a[i]);
//        }
//        p+=z-mi;
//        ll mp=INT64_MAX;
//        ll mq = 0;
//        vll b;
//        b.pb(mx);
//        mp=min(mx,mi);
//        mq=max(mx,mi);
//        for(ll i=m[y]+1;i<mm[z];i++)
//        {
//            b.pb(a[i]);
//            mp=min(mp,a[i]);
//            mq=max(mq,a[i]);
//        }
//        b.pb(mi);
//        if(!is_sorted(all(b))){
//            p+=mp-mq;
//        }
//        ans=min(ans,p);
//    }
//    cout<<ans<<endl;
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








