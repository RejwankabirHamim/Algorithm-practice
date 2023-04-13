//https://lightoj.com/problem/underwater-snipers
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
ll ar[500005],br[500005],cr[500005],dr[500005];
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,z,l2,q,l,r,r2,x,y;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        ll d,s,a,b,c,l1,r1;
        z=0;
        cin>>k>>n>>s>>d;
        fr(i,n,1)cin>>ar[i]>>br[i],z=max(z,br[i]);
        cout<<"Case "<<w1<<": ";
        if(z-k>=d)
        {
            cout<<"impossible"<<endl;
            ct;
        }
        l1=z-d,r1=k-1;
        while(l1<=r1)
        {
               // dbg(l1);
               // dbg(r1);
            z=(l1+r1)/2;
           // dbg(z);
            vector<pa>v;
            set<pa>st;
            fr(i,n,1)
            {
                c=ar[i]*ar[i]-d*d+(br[i]-z)*(br[i]-z);
                b=-2*ar[i];
                a=sqrtl(b*b-4*c);
                a/=2;
                cr[i]=(-b/2)-a;
                dr[i]=(-b/2)+a;
                st.insert({dr[i],i});
                v.pb({cr[i],i});
            }
            sort(all(v));
            x=0;
            l=0;
            while(!st.empty())
            {
                auto it=st.begin();
                r=(*it).ff;
                x++;
                while(l<n&&v[l].ff<=r)st.erase({dr[v[l].ss],v[l].ss}),l++;
            }
            if(x>s)l1=z+1;
            else r1=z-1;
//            dbg(l1);
//            dbg(r1);
        }
        l=k-l1;
        if(l<=0)cout<<"impossible"<<endl;
        else cout<<l<<endl;
    }
}
