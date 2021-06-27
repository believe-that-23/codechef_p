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
// vector<vll> readGraph(ll n,ll m){
//    vector<vll> g(n);
//    for(ll i=0;i<m;i++){
//        ll a,b;
//        cin>>a>>b;
//        //sc.read(a,b);
//        //a--;b--;
//        g[a].pb(b);
//        g[b].pb(a);
//    }
//    return g;
// }
// vector<vll> readTree(int n){
//    return readGraph(n,n-1);
// }
//----------------------------------------------------------------------------
vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
vector<bool> primes(1e7+5,true);
void solve()
{
   ll n;
   cin>>n;
   ll group=1;
   for(ll i=3;i<=n;i+2){
       if(primes[i]&&i*2>n)group++;
   }
    cout<<group<<endl;
}
int main() {


primes[0] = primes[1] = false;
for (ll i = 3; i * i <= 1e7; i++) {
    if (primes[i]) {
        for (ll j = i * i; j <= 1e7; j += i)
            primes[j] = false;
    }
}


FAST;
ll t;
cin>>t;
while(t--){
   solve();
}
return 0;
}