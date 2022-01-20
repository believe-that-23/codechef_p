#include <bits/stdc++.h>
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

//-----------------------------------------------------------
//vll tree;
//ll query(ll node,ll left,ll right,ll l,ll r){
//    if(left>r||right<l)return 0;
//    if(left>=l&&right<=r){
//        return tree[node];
//    }
//    ll mid=(left+right)/2;
//    ll sum=(query(2*node,left,mid,l,r)
//    ,query(2*node+1,mid+1,right,l,r));
//    return sum;
//}
class Segment_Tree
{
      vector<ll> seg;
      vector<ll> array;
      public:
      Segment_Tree(ll size, vector<ll> arr)
      {
            ll x =  4;
            ll n= x*size+1;
            seg.resize(n+1,INT64_MAX);
            array = arr;
      }
      ll construct_tree(ll start,ll l, ll r)
      {
          if(l==r)
          {
              seg[start]=array[l];
              return array[l];
          }
          ll mid = (l+r)/2;
          seg[start] = min(construct_tree(2*start+1,l,mid),construct_tree(2*start+2,mid+1,r));
          return seg[start]; 
      }
      ll get_max(ll index,ll start,ll end, ll l, ll r)
      {
          if(l<=start && r>=end)
          return seg[index];
          if(end<l || start>r)
          return INT64_MAX;
          ll mid = (start+end)/2;
          return min(get_max(2*index+1,start,mid,l,r) , get_max(2*index+2,mid+1,end,l,r));
 
      }
};
void solve()
{
    ll n;
    cin>>n;
    vll a(n);
    map<ll,ll> m;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    Segment_Tree tree(n,a);
    tree.construct_tree(0,0,n-1);
    ll mm=n;

    for(ll i=mm-1;i>=0;i--){
        m[a[i]]=i;
    }
    vll s(n);
    s[n-1]=a[mm-1];
    for(ll i=mm-2;i>=0;i--){
        s[i]=min(a[i],s[i+1]);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    ll ans=0;
    ll lst=-1;
    for(ll i=a.size()-1;i>=0;i--){
        if(lst==-1){
            ans+=a[i]-s[m[a[i]]];
            lst=m[a[i]];
        }
        else{
            if(m[a[i]]>=lst){            
                continue;
            }
            else{
                ans+=a[i]-tree.get_max(0,0,n-1,m[a[i]],lst-1);
                lst=m[a[i]];
            }
        }
    }
    ans=min(ans,a.back()-a[0]);
    cout<<ans<<endl;
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








