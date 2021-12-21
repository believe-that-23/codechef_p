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

vll ans(100005);

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s.erase(unique(all(s)),s.end());
    n=s.size(); 

    if(ans[n-1]==1)cout<<"SAHID"<<endl;
    else cout<<"RAMADHIR"<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ans[0]=1;
    ans[1]=0;
    for (ll i = 2; i < 100005; i++) {
        set<ll> s;
        s.insert(ans[i-1]);
        s.insert(ans[i-2]);
        if(s.size()==2)ans[i]=1;
        else ans[i]=0;
    }
    ll t=1;
    cin>>t;
    for(ll i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}








