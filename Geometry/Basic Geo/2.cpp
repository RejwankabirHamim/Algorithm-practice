//https://lightoj.com/problem/pair-of-touching-circles
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
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,z,l2,q,l,r,r2,x,y;
    te=1;
    fr(i,1000,0)cr[i*i]=i;
    cin>>te;
    fr(w1,te,1)
    {
        cin>>n>>m;
        z=0;
        fr(i,n/2,0)
        {
            fr(j,m/2,0)
            {
                if(i+j==0||cr[i*i+j*j]==0)ct;
                x=cr[i*i+j*j];
                fr(k,x-1,1)
                {
                    r2=x-k;
                    l=max(0LL,min(n-k,n-i-r2)-max(k,r2-i)+1);
                    r=max(0LL,min(m-r2-j,m-k)-max(k,r2-j)+1);
                    z+=(l*r);
                    if(j)r=max(0LL,min(m-r2+j,m-k)-max(k,r2+j)+1);
                    else r=0;
                    //dbg(r);
                    if(i)z+=(l*r);
                }
            }
        }
        cout<<"Case "<<w1<<": "<<z<<endl;
    }
}
