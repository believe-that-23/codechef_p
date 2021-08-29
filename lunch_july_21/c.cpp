#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
#define endl "\n"
ll C(ll n, ll k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
       res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<vll> readGraph(ll n,ll m){
    vector<vll> g(n);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        //sc.read(a,b);
        //a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return g;
}
vector<vll> readTree(int n){
    return readGraph(n,n-1);
}
//----------------------------------------------------------------------------
void solve()
{
    int n,k,s;
    cin>>n>>k>>s;
    vector<int> a(n);
    vector<vector<int>> nxt(n+1,vector<int>(19));
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int p=0;
    int sum=0;
    for (int i = 0; i < n; i++) {
        while(p<n&&sum+a[p]<=s){
            sum+=a[p];
            p++;
        }
        nxt[i][0]=p;
        sum-=a[i];
    }
    for (int i = 0; i < 19; i++) {
        nxt[n][i]=n;
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j < 19; j++) {
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
        }
    }
    int ans=0;
    for (int i = 0; i < n; i++) {
        int cur=k;
        int p=i;
        for (int j = 0; j < 19; j++) {
            while(cur>=(1<<j)){
                cur-=1<<j;
                p=nxt[p][j];
            }
        }
        ans=max(ans,p-i);
    }
    cout<<ans<<endl;



    /*k--;
    s*=k;
    ll ans=0;
    ll sum=0;
    ll l=0;
    ll r=n-1;
    while(l<=r){
        sum=pref[r+1]-pref[l];
        if(sum>s){
            if(a[l]<a[r]){
                r--;
            }
            else{
                l++;
            }
        }else{
            ans=r-l+1;
            break;
        }
    }
    if(ans<k){
        ans=k;
    }

    cout<<ans<<endl;
    */
}
int main() {
FAST;
int t;
cin>>t;
while(t--){
   solve();
}
return 0;
}








