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
    ll p,x,y;
    cin>>p>>x>>y;
    vll a(n);
    vll pref(n);
    ll z=0;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i]){
            a[i]=y;
        }else{
            a[i]=x;
        }
        z+=a[i];
        pref[i]=z;
    }
    cout<<pref[p-1]<<endl;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








