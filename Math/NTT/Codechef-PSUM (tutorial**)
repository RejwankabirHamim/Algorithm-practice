//https://www.codechef.com/SEPT19A/problems/PSUM
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
//#define M  998244353 // 1000000007  //
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

const ll mod =  998244353;
//For 10^9 + 7 : {7340033, 415236097, 463470593}

inline ll add(ll x, ll y) {x += y; return x >= mod ? x - mod : x;}
inline ll sub(ll x, ll y) {x -= y; return x < 0    ? x + mod : x;}
inline ll mul(ll x, ll y) {return (x * y) % mod;}
inline ll Pow(ll x, ll y){
    ll res = 1;
    while(y){
        if(y & 1) res = (res * x) % mod;
        y >>= 1, x = (x * x) % mod;
    }
    return res;
}

struct NTT{
    vector<ll> A,B;
    vector<ll> root, rev;
    ll P,M,G;

    NTT(ll mod) {P = mod; G = 10;}
    void init(int n){
        M = 1; int z = 0;
        while(M < n) M <<= 1, z++;
        M <<= 1; z++;

        A.resize(M); B.resize(M);
        root.resize(M); rev.resize(M);
        for(int i = 1; i < M; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (z - 1);

        int x = Pow(G, (P-1) / M);
        root[0] = 1;
        for(int i = 1; i < M; i++) root[i] = mul(root[i-1], x);
    }

    void ntransform(vector<ll> &a,ll f){
        if(f) reverse(a.begin() + 1, a.end());
        for (ll i = 0; i < M; i++) if(i < rev[i]) swap(a[i],a[rev[i]]);
        for (ll i = 1; i < M; i <<= 1){
            for (ll j = 0, t = M / (i << 1); j < M; j += i << 1){
                for (ll k = 0, l = 0; k < i; k++, l += t){
                    ll x = a[j + k];
                    ll y = mul(a[j + k + i], root[l]);
                    a[j + k] = add(x, y);
                    a[j + k + i] = sub(x, y);
                }
            }
        }

        if(f){
            ll inv = Pow(M, P-2);
            for(ll i = 0; i < M; i++) a[i] = mul(a[i], inv);
        }
    }

    void multiply( vector<ll> &X, vector<ll> &Y, vector<ll> &res){
        init(max(X.size(), Y.size()));
        for (ll i = 0; i < M; i++) A[i] = B[i] = 0;
        for (ll i = 0; i < X.size(); i++) A[i] = X[i];
        for (ll i = 0; i < Y.size(); i++) B[i] = Y[i];
        ntransform(A, 0); ntransform(B, 0);
        res.clear(); res.resize(M);
        for (ll i = 0; i < M; i++) res[i] = mul(A[i], B[i]);
        ntransform(res, 1);
    }
} ntt(mod);
long long int mod_inverse(long long int x,long long int p)//x is fact[i] and p is M-2
{
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}
vector<ll>dp[102][102];
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    dr[0]=1;
    fr(i,2000,1)dr[i]=(dr[i-1]*i)%mod;
    ar[2000]=mod_inverse(dr[2000],mod-2);
    rfr(i,1999,0)ar[i]=(ar[i+1]*(i+1))%mod;
    //dbg((dr[4]*ar[4])%mod);
    //cin>>te;
    fr(w1,te,1)
    {

        ll s;
        cin>>n>>s>>k;
        fr(i,n,1)cin>>cr[i]>>br[i];
        dp[0][0].pb(1);
        fr(i,k,1)dp[0][0].pb(0);
        z=0;
        fr(i,n,1)
        {
            fr(j,s,0)
            {
                if(dp[i-1][j].size()!=0)dp[i][j]=dp[i-1][j];
                if(j>=cr[i])
                {
                    vector<ll>tmp,tmp1;
                    x=1;
                    fr(l,k,0)
                    {
                        tmp.pb((x*ar[l])%mod);
                        x=(x*br[i])%mod;
                    }
                    ntt.multiply(tmp,dp[i-1][j-cr[i]],tmp1);
                    while(tmp1.size()>(k+1))tmp1.pop_back();
                    if(dp[i][j].size())
                    {
                        fr(l,k,0)dp[i][j][l]=add(dp[i][j][l],tmp1[l]);
                    }
                    else dp[i][j]=tmp1;
                }
                if(i==n&&dp[i][j].size()==k+1)z=add(z,dp[i][j][k]);
                //dbg(z);
            }
        }
        z=(z*dr[k])%mod;
        cout<<z<<endl;
    }
}
