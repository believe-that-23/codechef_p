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
    string s[n];
    string ans="";
    vll a(n,1);
    for (ll i = 0; i < n; i++) {
        cin>>s[i];
    }
    for (ll i = 0; i < n; i++) {
        ll z=s[i][i]-'0';
        cout<<!z;
    }
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








