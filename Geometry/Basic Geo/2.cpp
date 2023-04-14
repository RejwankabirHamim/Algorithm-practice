//https://lightoj.com/problem/trapezium-drawing
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
double calarea(double a,double b,double c)
{
    double s=(a+b+c)/2;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
}
bool ccw(pair<double,double> a, pair<double,double>b, pair<double,double> c) {
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) > 0;
}
int main()
{
    fast;
    ll te,n,i,j,k,w1,z,l2,q,l,r,r2;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        double ax,ay,bx,by,cx,cy,dx,dy,b,c,d,a,area,h,c2,c1,m;
        cin>>ax>>ay>>bx>>by>>b>>c>>d;
        a=sqrtl((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        area=calarea(a-c,b,d);
        h=(2*area)/(a-c);
        //dbg(h);
        double a1,b1,c3,d1,x,y;
        vector<pair<double,double>>v;
        if(bx==ax)
        {
            if(ay<by)h=-h;
            a1=1;
            b1=-2*ay;
            c3=ay*ay+h*h-d*d;
            d1=sqrtl(b1*b1-4*a1*c3);
            x=(-b1+d1)/(2*a1);
            v.pb({ax+h,x});
            x=(-b1-d1)/(2*a1);
            v.pb({ax+h,x});

            a1=1;
            b1=-2*by;
            c3=by*by+h*h-b*b;
            d1=sqrtl(b1*b1-4*a1*c3);
            x=(-b1+d1)/(2*a1);
            v.pb({ax+h,x});
            x=(-b1-d1)/(2*a1);
            v.pb({ax+h,x});
            x=100;
            fr(i,1,0)
            {
                fr(j,3,2)
                {
                    y=sqrtl((v[i].ff-v[j].ff)*(v[i].ff-v[j].ff)+(v[i].ss-v[j].ss)*(v[i].ss-v[j].ss));
                    if(abs(y-c)<x)
                    {
                        l=i,r=j;
                        x=abs(y-c);
                    }
                }
            }
            cout<<"Case "<<w1<<": "<<endl;
            cout<<fixed<<setprecision(8)<<v[r].ff<<" "<<v[r].ss<<" "<<v[l].ff<<" "<<v[l].ss<<endl;
            ct;
        }
        m=(by-ay)/(bx-ax);
        c2=-m*ax+ay;
        if(ax<bx)c1=h*sqrtl(m*m+1)+c2;
        else c1=-h*sqrtl(m*m+1)+c2;
        a1=m*m+1;
        b1=-2*ax-2*ay*m+2*m*c1,c3=ax*ax+ay*ay-2*ay*c1+c1*c1-d*d;
        d1=sqrtl(b1*b1-4*a1*c3);
        x=(-b1+d1)/(2*a1);
        v.pb({x,m*x+c1});
        x=(-b1-d1)/(2*a1);
        v.pb({x,m*x+c1});
        b1=-2*bx-2*by*m+2*m*c1;
        c3=bx*bx+by*by-2*by*c1+c1*c1-b*b;
        d1=sqrt(b1*b1-4*a1*c3);
        x=(-b1+d1)/(2*a1);
        v.pb({x,m*x+c1});
        x=(-b1-d1)/(2*a1);
        v.pb({x,m*x+c1});
        x=100;
        fr(i,1,0)
        {
            fr(j,3,2)
            {
                y=sqrtl((v[i].ff-v[j].ff)*(v[i].ff-v[j].ff)+(v[i].ss-v[j].ss)*(v[i].ss-v[j].ss));
                if(abs(y-c)<x)
                {
                    l=i,r=j;
                    x=abs(y-c);
                }
            }
        }
        cout<<"Case "<<w1<<": "<<endl;
        cout<<fixed<<setprecision(8)<<v[r].ff<<" "<<v[r].ss<<" "<<v[l].ff<<" "<<v[l].ss<<endl;
    }
}
