//https://lightoj.com/problem/intersection-of-cubes
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M  998244353 // 1000000007  //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define endl '\n'
ll ar[500005],br[500005],cr[500005],dp[500005];

int main()
{
    fast;
    ll te,n,m,i,j,k,w1,z,l2,q,l,r,x,y;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        cin>>n;
        l=x=j=0,r=y=k=1001;
        fr(i,n,1)
        {
            ll x1,x2,y1,y2,z1,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            l=max(l,x1),r=min(r,x2),x=max(x,y1),y=min(y,y2),j=max(j,z1),k=min(k,z2);
        }
        z=max(0LL,r-l)*max(0LL,y-x)*max(0LL,k-j);
        cout<<"Case "<<w1<<": "<<z<<endl;
    }
}
