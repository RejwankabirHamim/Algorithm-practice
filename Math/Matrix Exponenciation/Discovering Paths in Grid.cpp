//https://lightoj.com/problem/discovering-paths-in-grid
#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define pb push_back
const int mod =  1000000007;
struct Mat {
  int n, m;
  vector<vector<int>> a;
  Mat() { }
  Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
  Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (int i = 0; i < n; i++)  {
      for (int j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
      }
    }
    return ans;
  }
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < b.m; j++) {
        for(int k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] ) % mod;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    if(k==0)
    {
        Mat ans(n, n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)ans.a[i][j]=1;
                else ans.a[i][j]=0;
            }
        }
    }
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i,j;
  int tc,cs;
  Mat init(35,35);
  int mp[136];
  for(i=0;i<=128;i++)mp[i]=-1;
  int hs=0;
  for(i=0;i<128;i++)
  {
      int cal=0;
      for(j=0;j<10;j++)
      {
          if(i&(1<<j))cal++;
      }
      if(cal==4)mp[i]=hs++;
  }
  for(i=0;i<128;i++)
  {
      if(mp[i]==-1)continue;
      for(j=0;j<128;j++)
      {
          if(mp[j]==-1)continue;
          set<int>st;
          vector<int>fst1;
          for(int l=0;l<10;l++)
          {
              if(i&(1<<l))st.insert(l);
              if(j&(1<<l))fst1.pb(l);
          }
          int flg=1;
          for(auto u:fst1)
          {
              if(st.count(u-1))
              {
                  st.erase(u-1);
                  continue;
              }
              if(st.count(u+1))
              {
                  st.erase(u+1);
                  continue;
              }
              flg=0;
              break;
          }
          init.a[mp[i]][mp[j]]=flg;
      }
  }
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k,x,y;
      cin >> n ;
      int cl=0;
      for(i=0;i<7;i++)
      {
          cin>>x;
          if(x)cl+=(1<<i);
      }
      cl=mp[cl];
      int ans=0;
      if(n==1)ans=1;
      else
      {
          Mat tot=init.pow(n-1);


        for(j=0;j<35;j++)ans=(ans+tot.a[cl][j])%mod;
          ans=(ans+mod)%mod;
      }
      cout<<"Case "<<cs<<": "<<ans<<endl;

  }
  return 0;
}
