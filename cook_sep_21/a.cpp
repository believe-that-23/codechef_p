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
    ll o=0,e=0;
    vll od,ev;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i]&1){
            o++;
            od.pb(a[i]);
        }
        else{
            e++;
            ev.pb(a[i]);
        }
    }
    if(o==0){
        cout<<-1<<endl;
        return;
    }
    if(e==0&&o%2==0){
        cout<<-1<<endl;
        return;
    }
    vll ans(n);
    ll k=0;
    for(auto c:ev)cout<<c<<" ";
    for(auto c:od)cout<<c<<" ";
    cout<<endl;
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








