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
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll z=*max_element(all(a));
    vll ans;
    for (ll i = 0; i < n; i++) {
        if(a[i]==z){
            ans.pb(i);
        }
    }
    ll f_ans=0;
    for(auto c:ans){
        if(c+1<k)continue;
        f_ans+=abs(n-c);
    }
    cout<<f_ans<<endl;

    
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








