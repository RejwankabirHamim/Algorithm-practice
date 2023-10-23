//https://csacademy.com/contest/beta-round-8/task/cube-coloring
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M   998244353 //1000000007  //
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
ll ar[500005],br[1000005],cr[1000005],dr[1000005];
ll ncr(ll n,ll r)
{
    if(n<r||n<0||r<0)return 0;
    ll z=1,i;
    fr(i,n,n-r+1)z=(z*i);
    fr(i,r,1)z/=i;
    return z;
}
int main()
{
    //fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    //cin>>te;
    fr(w1,te,1)
    {
        cin>>n;
        z=0,y=0;
        fr(i,n,1)cin>>x,y+=(x>=2);
        z=(z+ncr(n,6)*30LL);
        x=(ncr(y,1)*ncr(n-1,4)*3);
        z=(z+x);
        z=(z+ncr(y,2)*ncr(n-2,2));
        z=(z+ncr(y,3));
        cout<<z<<endl;
    }
}
