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
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll cnt=0;
    ll i=0;
    while(true){
        if(i==n)break;
        if(a[i]!=i+1){
            ll temp=a[i];
            while(temp!=i+1){
                for (ll j = 0; j < n; j++) {
                    if(a[j]==temp){
                        ll z=j+k;
                        if(z>=n){
                            z=n;
                        }
                        cnt++;
                        sort(a.begin()+j,a.begin()+z);
                        break;
                    }
                }
            }
        }
        i++;
    }
    cout<<cnt<<endl;
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








