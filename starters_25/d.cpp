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
    ll n,k;
    cin>>n>>k;
    vll a(n);
    iota(all(a),1);
    ll ans=n*(n+1)/2;
    if(ans==k){
        for(auto c:a)cout<<c<<" ";
        cout<<endl;
        return;
    }
    if(k==n){
        for(ll i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    ll ind=-11;
    for (ll i = 0; i < n; i++) {
        ll z=(i+1)*(i+2)/2;
        ll temp=z+n-1-i;
        if(temp>k){
           ind=i-1; 
           break; 
        }
    }
    ll temp=(ind+1)*(ind+2)/2; 
    temp+=n-1-(ind+1);
    ll l=1,r=a[ind];
    ll f=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll s=a[ind]-mid;
        s++;
        if(s==k-temp){
            f=mid;
            break;
        }
        else if(s<k-temp){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    for(ll i=ind+1;i<n;i++){
        a[i]=f;
    }
    for(auto c:a)cout<<c<<" ";
    cout<<endl;
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








