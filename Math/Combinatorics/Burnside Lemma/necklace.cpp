#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M   1000000007  //
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
ll ar[500005],br[500005],cr[500005],dr[500005];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long int mod_inverse(long long int x,long long int p)//x is fact[i] and p is M-2
{
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%M)*(x%M))%M;
        y=y>>1;
        x=((x%M)*(x%M))%M;
    }
    return res;
}
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        cin>>n>>k;
        z=0;
        fr(i,n-1,0)
        {
            x=__gcd(i,n);
            x=binpow(k,x,M);
            z=(z+x)%M;
        }
        z=(z*mod_inverse(n,M-2))%M;
        cout<<"Case "<<w1<<": "<<z<<endl;
    }
}
