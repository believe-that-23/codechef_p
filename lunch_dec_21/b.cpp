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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    deque<char> d;
    for (ll i = 0; i < k; i++) {
        d.pb(s[i]);
    }
    string t="";
    while(!d.empty()){
        t+=d.front();
        d.ppf;
        if(!d.empty()){
            t+=d.back();
            d.ppb;
        }
    }
    reverse(all(t));
    for(ll i=k;i<n;i++){
        t+=s[i];
    }
    cout<<t<<endl;
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








