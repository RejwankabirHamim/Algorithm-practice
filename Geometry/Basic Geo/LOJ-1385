//https://lightoj.com/problem/kingdom-division
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
        double a,b,c,d1,d2,d;
        cin>>a>>b>>c;
        cout<<"Case "<<w1<<": ";
        if(a==0||b==0||c==0)
        {
            cout<<-1<<endl;
            ct;
        }
        d1=(a*c)/b;
        if(b<=d1)
        {
            cout<<-1<<endl;
            ct;
        }
        d2=(d1*d1+d1*c+a*d1+a*c)/(b-d1);
        d=d1+d2;
        cout<<fixed<<setprecision(6)<<d<<endl;
    }
}
