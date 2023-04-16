//https://lightoj.com/problem/speed-zones
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
ll ar[500005],br[500005],cr[1000005],dp[1005][1005];
double solve(double s,double lmd)
{
    return sqrtl((10000*s*s*lmd)/(1-s*s*lmd));
}
int main()
{
    fast;
    ll te,n,i,j,k,w1,z,l2,q,l,r,r2;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        double s[105];
        double d,low,high,mid,mn=100,tot,x[105];
        cin>>n>>d;
        fr(i,n,1)cin>>s[i],mn=min(mn,1.0/(s[i]*s[i]));
        low=0,high=mn;
        fr(i,50,1)
        {
            mid=(low+high)/2;
            tot=0;
            fr(j,n,1)x[j]=solve(s[j],mid),tot+=x[j];
            if(tot>d)high=mid;
            else low=mid;
        }
        double ans=0;
        fr(i,n,1)ans+=(sqrtl(10000+x[i]*x[i])/s[i]);
        cout<<"Case "<<w1<<": "<<fixed<<setprecision(6)<<ans<<endl;
    }
}
