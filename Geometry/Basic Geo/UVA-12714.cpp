//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4452
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
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x=x1-x2;
        y=y1-y2;
        swap(x,y);
        y=-y;
        l=0,r=0;
        if(x<0)l-=x,x=0;
        if(y<0)r=-y,y=0;
        cout<<"Case "<<w1<<": "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
    }
}
