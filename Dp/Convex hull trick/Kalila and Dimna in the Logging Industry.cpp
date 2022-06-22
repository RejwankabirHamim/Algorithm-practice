#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100005],brr[100005],dp[100005];
vector<ll>b,m;
bool bad(int f1,int f2,int f3)
{
   // return __int128(b[f3] - b[f1]) * (m[f1] - m[f2]) <=__int128(b[f2] - b[f1]) * (m[f1] - m[f3]);
  return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) <=1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
}
void add(long long m_, long long b_) {
  m.push_back(m_); b.push_back(b_); // push in CHT
  int sz = m.size();
  while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
    m.erase(m.end() - 2); // remove f2's m
    b.erase(b.end() - 2); // remove f2's b
    sz--; // size is decreased by 1
  } // we remove f2's while we can
}
ll f(int i, ll x) { return m[i] * x + b[i]; }
ll query(ll x) {
  int  lo = 0, hi = m.size() - 1;
  ll ans = 1e18;
  while(lo <= hi) {
       // if(x==10)cout<<lo<<" "<<hi<<endl;
    int mid1 = (lo + lo + hi) / 3;
    int mid2 = (lo + hi + hi) / 3;
    ll y1 = f(mid1, x), y2 = f(mid2, x);
    if(y1 < y2) ans =min(ans,y1), hi = mid2 - 1;
    else ans =min(ans,y2), lo = mid1 + 1;//min is very important!
  } return ans;
}
int main()
{
     long long int t,n,x,y,z,i,j;
     cin>>n;
     for(i=1;i<=n;i++)cin>>arr[i];
     for(i=1;i<=n;i++)cin>>brr[i];
     for(i=1;i<=n;i++)
     {
         if(i==1)dp[i]=0;
         else
         {
             dp[i]=query(arr[i]);
         }
         //if(i==4)cout<<m[1]<<" "<<b[1]<<endl;
         add(brr[i],dp[i]);
        // cout<<dp[i]<<" ";
     }
     cout<<dp[n]<<endl;
}
