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
    set<ll> s;
    ll sum=0;
    ll cnt=0;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i]!=0){
            cnt++;
            s.insert(i);
            sum+=a[i];
        }
    }
    ll p=s.size();
    while(p<n&&k--){
        set<ll> tmp;
        for(auto c:s){
           ll x=c-1;
           ll y=c+1;
           sum+=2;
           if(x<0)x+=n;
           if(y>=n)y-=n;
           if(!s.count(x))
               tmp.insert(x);
           if(!s.count(y))
               tmp.insert(y);
        }
        for(auto c:tmp)s.insert(c);
        p=s.size();
    }
    if(k>0){
        sum+=k*2*n;
    }
    cout<<sum<<endl;
    
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








