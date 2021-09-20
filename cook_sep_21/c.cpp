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
    string s,t;
    cin>>s>>t;
    ll cnt=0;
    ll c1=0;
    ll c0=0;
    if(s==t){
        cout<<"YES"<<endl;
        return;
    }
    set<char> ss;
    for (ll i = 0; i < n; i++) {
        ss.insert(t[i]); 
    }
    if(ss.size()==1){
        cout<<"NO"<<endl;
        return;
    }
    for (ll i = 0; i < n; i++) {
        if(t[i]=='1')c1++;
        else c0++;
    }
    if(c1&&c0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


 
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








