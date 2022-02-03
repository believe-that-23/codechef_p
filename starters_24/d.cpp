#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define eb emplace_back
#define mp make_pair
#define ll long long
#define lld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;
using namespace __gnu_pbds;
//#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>

//-----------------------------------------------------------

ll phi(ll n)
{
     
    // Initialize result as n
    float result = n;
  
    // Consider all prime factors of n
    // and for every prime factor p,
    // multiply result with (1 - 1/p)
    for(ll p = 2; p * p <= n; ++p)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0)
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result *= (1.0 - (1.0 / (float)p));
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));
  
    return (ll)result;
}
ll sumofFactors(ll n)
{
    // Traversing through all prime factors.
    ll res = 1;
    for (ll i = 2; i <= sqrt(n); i++)
    {
 
         
        ll curr_sum = 1;
        ll curr_term = 1;
        while (n % i == 0) {
 
            // THE BELOW STATEMENT MAKES
            // IT BETTER THAN ABOVE METHOD
            //  AS WE REDUCE VALUE OF n.
            n = n / i;
 
            curr_term *= i;
            curr_sum += curr_term;
        }
 
        res *= curr_sum;
    }
 
    // This condition is to handle
    // the case when n is a prime
    // number greater than 2.
    if (n >= 2)
        res *= (1 + n);
 
    return res;
}
map<ll,ll> m;

void solve()
{
    ll x,a,b;
    cin>>x>>a>>b;
    if(a==1&&b==1){
        if(x==1){
            cout<<1<<endl;
        }
        else cout<<-1<<endl;
        return;
    }

    ll n=x*b;
    if(n%a!=0){
        cout<<-1<<endl;
        return;
    }
    n/=a;

    cout<<n<<endl;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}








