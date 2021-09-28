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
    string s;
    cin>>s;
    s.erase(unique(all(s)),s.end());
    ll ans=0;
    if(s[0]!='1')ans++;
    for(ll i=1;i<s.size();i++){
        if(s[i]!=s[i-1])ans++;
    }
    cout<<ans<<endl;

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








