#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e14
ll a[100005],dp[100004];
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
ll query(ll x) {
  if(ptr >= m.size()) ptr = m.size() - 1;
  while(ptr < m.size() - 1 &&
    f(ptr, x) > f(ptr+1, x)) ptr++;
  return f(ptr, x);
}
int main()
{
     long long int t,n,k,x,y,z,i,j;
     cin>>n;
     vector<pair<int,int>>v1,v2,v;
     for(i=1;i<=n;i++)cin>>x>>y,v1.push_back({x,y});
     sort(v1.begin(),v1.end());
     for(i=0;i<n;i++)
     {
         while(v2.size()!=0)
         {
             pair<int,int>p;
             p=v2.back();
             if(p.first>v1[i].second)
                break;
             else v2.pop_back();
         }
         v2.push_back({v1[i].second,i});
     }
     v.push_back({0,0});
     for(i=0;i<v2.size();i++)
     {
         v.push_back(v1[v2[i].second]);
     }
     for(i=1;i<v.size();i++)
     {
         add(v[i].second,dp[i-1]);
         dp[i]=query(v[i].first);

     }
   //  for(i=0;i<m.size();i++)cout<<m[i]<<" "<<b[i]<<endl;
     x=v.size();
     cout<<dp[x-1]<<endl;

}
