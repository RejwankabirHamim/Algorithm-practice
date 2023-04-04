//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1507
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
double cal(double x,double y,double d)
{
    double y1=sqrtl(x*x-d*d);
    double y2=sqrtl(y*y-d*d);
    double ans=(y1*y2)/(y1+y2);
    return ans;
}
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,z,l2,k2,k1,q,l,r;
    te=1;
    //cin>>te;
    double x,y,c;
    while(cin>>x>>y>>c)
    {
        double low=0,high=min(x,y),mid;
        fr(i,50,1)
        {
            mid=(low+high)/2;
            if(cal(x,y,mid)>c)low=mid;
            else high=mid;
        }
        cout<<fixed<<setprecision(3)<<low<<endl;
    }
}
