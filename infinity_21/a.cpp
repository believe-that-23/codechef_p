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
    string s,p;
    cin>>s>>p;
    set<char> ss={'a','e','i','o','u'};
    ll ans=INT64_MAX;
    for(auto c:ss){
        string q="",r="";
        for (ll i = 0; i < n; i++) {
            if(s[i]=='?'){
                q+=c;
            }
            else{
                q+=s[i];
            }
            if(p[i]=='?'){
                r+=c;
            }
            else{
                r+=p[i];
            }
        }
        ll temp=0;
        for (ll i = 0; i < n; i++) {
            if(r[i]!=q[i]){
                if(ss.count(q[i])&&ss.count(r[i])){
                    temp+=2;
                    continue;
                }
                if(ss.count(q[i])||ss.count(r[i])){
                    temp+=1;
                    continue;
                }
                temp+=2;
            }
        }
        ans=min(ans,temp);
    }
    for(char c='a';c<='z';c++){
        if(ss.count(c))continue;
        string q="",r="";
        for (ll i = 0; i < n; i++) {
            if(s[i]=='?'){
                q+=c;
            }
            else{
                q+=s[i];
            }
            if(p[i]=='?'){
                r+=c;
            }
            else{
                r+=p[i];
            }
        }
        ll temp=0;
        for (ll i = 0; i < n; i++) {
            if(r[i]!=q[i]){
                if(ss.count(q[i])&&ss.count(r[i])){
                    temp+=2;
                    continue;
                }
                if(ss.count(q[i])||ss.count(r[i])){
                    temp+=1;
                    continue;
                }
                temp+=2;
            }
        }
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
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








