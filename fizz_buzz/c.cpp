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
    ll n,m;
    cin>>n>>m;
    if(n==m){
        cout<<0<<endl;
        return;
    }
    ll z=n-m;
    ll x=(n-m+m-1)/m;
    cout<<x<<endl;
    ll ans=0;
    if(z%x==0){
        ll temp=z/x;
        temp*=(temp+1);
        temp/=2;
        temp*=x;
        ans+=temp;
    }
    else{
        ll temp=z/x;
        temp*=(temp+1);
        temp/=2;
        temp*=x;
        ans+=temp; 
        ll k=z%x;
        temp=k;
        temp*=(temp+1);
        temp/=2;
        temp*=k;
        ans+=temp;
    }
     
    cout<<x<<endl;
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








