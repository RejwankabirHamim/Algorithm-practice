#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e14
ll a[1000005],dp[1000004],p[1000005];
int ptr;
vector<ll>b,m;
bool bad(int f1,int f2,int f3)
{
  return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) <=1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
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
ll int query(ll x) {
  if(ptr >= m.size()) ptr = m.size() - 1;
  while(ptr < m.size() - 1 &&
    f(ptr, x) < f(ptr+1, x)) ptr++;
  return f(ptr, x);
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     long long int t,n,k,x,y,z,i,j;
     cin>>t;
     while(t--)
     {
         cin>>n>>x>>y>>z;
         m.clear(),b.clear();
         ptr=0;
         for(i=1;i<=n;i++)cin>>a[i];
         p[0]=dp[0]=0;
         for(i=1;i<=n;i++)
         {
             p[i]=p[i-1]+a[i];
         }
         for(i=1;i<=n;i++)
         {
             add(-2*x*p[i-1],x*p[i-1]*p[i-1]-y*p[i-1]+dp[i-1]);
             dp[i]=query(p[i]);
             dp[i]+=z+x*p[i]*p[i]+y*p[i];
         }
         cout<<dp[n]<<endl;

     }
}
