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
    map<ll,ll> m;
    
    vll diff(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        m[a[i]]++;
    }

    ll ans2=0;
    ll ans;

    for(auto c:m){
        ans2=max(ans2,c.se);
    }
    if(n>2){
        if(ans2==1)ans=n-2;
        else ans=n-ans2;
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








