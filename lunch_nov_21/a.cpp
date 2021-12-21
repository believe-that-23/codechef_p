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

const ll mod=998244353;

void solve()
{
    ll n,q;
    ll p=1;
    cin>>n;
    if (n%2==0){
        if(n%4==0){
            q=1;
            p=n/4;
            p%=mod;
            p*=(n+1);
            p%=mod;
            p*=(n+1);
            p%=mod;
        }
        else {
            q=2;
            p=n/2;
            p%=mod;
            p*=(n+1);
            p%=mod;
            p*=(n+1);
            p%=mod;
        }
    }
    else {
        q=1;
        p*=(n+1)/2;
        p%=mod;
        p*=(n+1)/2;
        p%=mod; 
        p*=n;
        p%=mod;
    } 
    ll inv=0;
    if (q==1){
        inv= 1;
    }
    else if (q==2){
        inv =499122177;
    }
    ll ans ;
    ans=p*inv;
    ans%=mod;
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









