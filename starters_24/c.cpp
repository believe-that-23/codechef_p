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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1){
        cout<<"NO"<<endl;
        return;
    }
    vll cnt(26);
    deque<pair<ll,char>> q;
    for (ll i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }
    for (char c='a';c<='z';c++){
        if(cnt[c-'a']>0){
            q.push_back(mp(cnt[c-'a'],c));
        }
    }
    sort(all(q));
    reverse(all(q));
    for(auto c:cnt){
        if(c>n/2){
            cout<<"NO"<<endl;
            return;
        }
    }
    vector<char> ans(n);
    for(ll i=n/2-1;i>=0;i--){
        ans[i]=q.front().se;
        q.front().fi--;
        if(q.front().fi==0)q.ppf;
    }
    for(ll i=n/2;i<n;i++){
        ans[i]=q.front().se;
        q.front().fi--;
        if(q.front().fi==0)q.ppf;
    }
    cout<<"YES"<<endl;
    for(auto c:ans)cout<<c;
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








