#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e14
ll a[200005],dp[14][100004],s[200005],p[200005];
int ptr;
vector<ll>b,m;
bool bad(int f1,int f2,int f3)
{
  return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) >=1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
}
void add(long long m_, long long b_) {
  m.push_back(m_); b.push_back(b_); // push in CHT
  int sz = m.size();
  // notice that f1 from discussion is in position sz - 3
  // f2 is in sz - 2, new line is in sz - 1
  while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
    m.erase(m.end() - 2); // remove f2's m
    b.erase(b.end() - 2); // remove f2's b
    sz--; // size is decreased by 1
  } // we remove f2's while we can
}
ll f(int i, ll x) { return m[i] * x + b[i]; }
ll query(ll x) {
  int  lo = 0, hi = m.size() - 1;
  ll ans = -1e18;
  while(lo <= hi) {
       // if(x==10)cout<<lo<<" "<<hi<<endl;
    int mid1 = (lo + lo + hi) / 3;
    int mid2 = (lo + hi + hi) / 3;
    ll y1 = f(mid1, x), y2 = f(mid2, x);
    if(y1 > y2) ans =max(ans,y1), hi = mid2 - 1;
    else ans =max(ans,y2), lo = mid1 + 1;
  } return ans;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     long long int t,n,k,x,y,z,i,j;
     cin>>n;
     for(i=1;i<=n;i++)cin>>a[i];
     for(i=1;i<=n;i++)
     {
         s[i]=s[i-1]+i*a[i];
         p[i]=p[i-1]+a[i];
     }
     x=LLONG_MIN;
     for(i=n-1;i>=0;i--)
     {
         add(i+1,-p[i+1]);
         y=query(a[i+1]);
         y+=p[i]+s[n]-i*a[i+1];
         x=max(x,y);
     }
     m.clear(),b.clear();
     for(i=0;i<n;i++)
     {
         add(-i,-p[i]);
         y=query(-a[i+1]);
         y+=s[n]+p[i+1]-(i+1)*a[i+1];
         x=max(x,y);
     }
     cout<<x<<endl;

}
