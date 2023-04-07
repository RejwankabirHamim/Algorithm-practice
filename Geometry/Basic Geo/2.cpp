//https://lightoj.com/problem/parallelogram-counting
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
    ll te,n,m,i,j,k,w1,z,l2,k2,k1,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
       // map<pair<int,int>,int>mp;
        vector<pa>v;
        cin>>n;
        fr(i,n,1)cin>>ar[i]>>br[i];
        z=0;
        fr(i,n,1)
        {
            fr(j,n,i+1)
            {
                l=ar[i]+ar[j];
                r=br[i]+br[j];
                v.pb({l,r});
            }
        }
        sort(all(v));
        fr(i,int(v.size()-2),0)
        {
            j=i;
            while(i<int(v.size()-2)&&v[i].ff==v[i+1].ff&&v[i].ss==v[i+1].ss)i++;
            k=(i-j);
            k=(k*(k+1))/2;
            z+=k;
        }
        cout<<"Case "<<w1<<": "<<z<<endl;
    }
}
