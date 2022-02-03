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
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vll p(n);
    vll pr(n);
    if(s[n-1]=='0')p[n-1]=1;
    if(s[0]=='0')pr[0]=1;
    for (ll i = 1; i < n; i++) {
        if(s[i]=='0'){
            pr[i]+=pr[i-1]+1;
        }
        else pr[i]=0;
    }
    for(ll i=n-2;i>=0;i--){
        if(s[i]=='0'){
            p[i]+=p[i+1]+1;
        }
        else p[i]=0;
    }
    ll ans=0;
    ll sum;
    for(ll i=n-1;i>=0;i--){
        if(pr[i]>0){
            ans+=pr[i]/x;
            sum+=pr[i];
            while(i&&pr[i]){
                i--;
            }
        }
    }
    ll f_ans=ans;
    for (ll i = 0; i < n; i++) {
        if(s[i]=='1'){
            ll temp1=(i==0?0:pr[i-1]);
            ll temp2=(i==n-1?0:p[i+1]);
            ll z=ans-temp1/x-temp2/x;
            z+=(temp1+temp2+1)/x;
            f_ans=max(f_ans,z);
        }
    }
    cout<<f_ans<<endl;
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








