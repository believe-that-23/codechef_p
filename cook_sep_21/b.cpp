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
    string s;
    cin>>s;
    string t=s;
    s.erase(unique(all(s)),s.end());
    ll jumps=s.size();
    if(s.size()<=k){
        cout<<-1<<endl;
        return;
    }
    if(k&1){
        for(ll i = n-1; i >= 0; i--) {
            if(t[i]!=t[0]){
                cout<<i+1<<endl;
                return;
            }
        }
    }
    else{
        for(ll i = n-1; i >= 0; i--) {
            if(t[i]==t[0]){
                cout<<i+1<<endl;
                return;
            }
        }
    }

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








