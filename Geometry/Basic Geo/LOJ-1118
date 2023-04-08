//https://lightoj.com/problem/incredible-molecules
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
struct pt {
    double x, y;
};
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
double area(double a,double b,double c)
{
    double s=(a+b+c)/2;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    fast;
    ll te,n,m,i,j,k,w1,z,l2,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        k=0;
        double x1,x2,r1,r2,y1,y2,k1,k2,k3,k4,a,b,c,x3,y3,x4,y4,dis,d;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(r1<r2)swap(x1,x2),swap(y1,y2),swap(r1,r2);
        if(x1==x2)swap(x1,y1),swap(x2,y2),k=1;
        dis=sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        cout<<"Case "<<w1<<": ";
        if(r1+r2>dis&&abs(r1-r2)<dis)
        {
            k1=x1*x1+y1*y1+r2*r2-x2*x2-y2*y2-r1*r1;
            k2=(y1-y2);
            k3=(x1-x2);
            k4=x1*x1+y1*y1-r1*r1;
            a=(k2/k3)*(k2/k3)+1.0;
            b=((2*k2*x1)/k3)-((k1*k2)/(k3*k3))-2*y1;
            c=0.25*(k1/k3)*(k1/k3)-((x1*k1)/k3)+k4;
            d=sqrtl(b*b-4*c*a);
            y3=(-b+d)/(2*a);
            y4=(-b-d)/(2*a);
            x3=(k1-2*k2*y3)/(2*k3);
            x4=(k1-2*k2*y4)/(2*k3);
            if(k)swap(x1,y1),swap(x2,y2),swap(x3,y3),swap(x4,y4);
            double tt1,tt2,dis1;
            dis1=sqrtl((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
            //dbg(dis1);
            tt1=2*asin(dis1/(2*r1));
            tt2=2*asin(dis1/(2*r2));
            pt a,b,c,d;
            a.x=x3,a.y=y3,b.x=x4,b.y=y4,c.x=x1,c.y=y1,d.x=x2,d.y=y2;
            if(cw(a,b,c)==cw(a,b,d))
            {
                double ans=(r1*r1*tt1*0.5)-area(r1,r1,dis1);
                ans+=((r2*r2*(2*pi-tt2)*0.5)+area(r2,r2,dis1));
                cout<<fixed<<setprecision(6)<<ans<<endl;
            }
            else
            {
                double ans=(r1*r1*tt1*0.5);
               // dbg(ans);
                ans-=area(r1,r1,dis1);
                //dbg(ans);
                ans+=((r2*r2*tt2*0.5)-area(r2,r2,dis1));
                cout<<fixed<<setprecision(6)<<ans<<endl;
            }
        }
        else if(abs(r1-r2)>=dis)
        {
            double ans=pi*r2*r2;
            cout<<fixed<<setprecision(6)<<ans<<endl;
        }
        else
        {
            cout<<0.00<<endl;
        }
    }
}
