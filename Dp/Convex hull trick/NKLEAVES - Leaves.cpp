#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e14
ll a[100005],dp[14][100004],s[100005],p[100005];
int ptr;
vector<ll>b,m;
bool bad(int f1,int f2,int f3)
{
  //  return __int128(b[f3] - b[f1]) * (m[f1] - m[f2]) <=__int128(b[f2] - b[f1]) * (m[f1] - m[f3]);  // only for gnu g++
  // or compare by taking the answer in double :D
  // as double can *store* at most 10^300 (with precision error :p)
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
    f(ptr, x) > f(ptr+1, x)) ptr++;
  return f(ptr, x);
}
int main()
{
     long long int t,n,k,x,y,z,i,j;
     cin>>n>>k;
     for(i=1;i<=n;i++)cin>>a[i];
     for(i=1;i<=n;i++)
     {
         s[i]=s[i-1]+i*a[i];
         p[i]=p[i-1]+a[i];
         //cout<<s[i]<<" "<<p[i]<<endl;
     }
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=k;j++)dp[j][i]=inf;
     }
     for(i=1;i<=n;i++)dp[1][i]=s[i]-p[i];
     for(i=2;i<=k;i++)
     {
         m.clear(),b.clear();
         ptr=0;
         for(j=i-1;j<=n;j++)
         {
             if(j>=i)dp[i][j]=query(p[j])+s[j];
             add(-(j+1),dp[i-1][j]-s[j]+(j+1)*p[j]);
         }
     }
     cout<<dp[k][n]<<endl;

}
