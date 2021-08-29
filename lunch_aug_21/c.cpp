#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;

//-----------------------------------------------------------


void solve()
{
    ll n;
    cin>>n;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll mm=*max_element(all(a));
    if(mm!=a[0]){
        cout<<-1<<endl;
        return;
    }
    vll dp(n);
    map<ll,ll> m;
    dp[n-1]=1;
    ll last=a[n-1];
    for(ll i=n-2;i>=1;i--){
        if(a[i]>last){
            dp[i]=1;
            last=a[i];
        }
    }
    ll ans=0;
    for (ll i = 0; i < n; i++) {
        if(dp[i]==1)ans++; 
    }
    cout<<ans<<endl;

}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while(t--){
    solve();
}
return 0;
}








