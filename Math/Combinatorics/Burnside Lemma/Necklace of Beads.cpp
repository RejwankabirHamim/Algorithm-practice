//http://poj.org/problem?id=1286
#include<iostream>
#include<math.h>
using    namespace std;
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
ll gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    //cin>>te;
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            cout<<0<<endl;
            ct;
        }
        if(n==-1)break;
        k=3;
        z=0;
        fr(i,n-1,0)
        {
            x=gcd(i,n);
            x=binpow(k,x);
            z=(z+x);
        }
        //dbg(z);
        if(n<=2)
        {
            z=z/n;
        }
        else
        {
            fr(i,n/2,1)
            {
                x=binpow(k,(n+1)/2);
                z=(z+x);
            }
            if(n%2==1)
            {
                fr(i,n,i)
                {
                    x=binpow(k,(n+1)/2);
                    z=(z+x);
                }
            }
            else
            {
                fr(i,n,i)
                {
                    x=binpow(k,(n+2)/2);
                    z=(z+x);
                }
            }
            z=z/(2*n);
        }
        cout<<z<<endl;
    }
}
