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
    string s;
    cin>>s;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        a[i]=s[i]-'0';
    }
    auto f=[&](ll x)->bool{
        ll sum=0;
        vll b=a;
        for(ll i=x;i>=0;i--){
            b[i]+=sum;
            b[i]%=10;
            if(b[i]!=0){
                sum+=10-b[i];
            }
        }
        if(sum<=k)return true;
        return false;
    };
    ll l=0,r=n-1;
    ll ans=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(f(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    if(ans==-1)cout<<0<<endl;
    else 
        cout<<ans+1<<endl;

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








