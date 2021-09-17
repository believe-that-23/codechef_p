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
    ll n,x;
    cin>>n>>x;
    ll sum=n*(n+1)/2;
    if(sum<=x){
        cout<<-1<<endl;
        return;
    }
    ll z=sum-x;
    if(z>n)cout<<-1<<endl;
    else cout<<z<<endl;
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








