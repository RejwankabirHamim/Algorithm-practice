//https://lightoj.com/problem/unlucky-strings
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int mod = 4294967296;
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
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
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
Mat cal(int n,int k,Mat org)
{
    if(k==1)return org;
    Mat ans=cal(n,k/2,org);
    ans=ans+org.pow(k/2)*ans;
    if(k&1)ans=ans+org.pow(k);
    return ans;
}
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i,j;
  int tc,cs;
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k;
      string all,s,tmp;
      cin >> n>>all>>s ;
      m=s.size();
      Mat org(m+1, m+1);

      for (int i = 0; i < m+1; i++) {
        for (int j = 0; j < m+1; j++) {
                org.a[i][j]=0;
        }
      }
      k=all.size();
      org.a[m][m]=k;
      int flg=0;
      for(i=0;i<m;i++)
      {
          int f=0;
          for(j=0;j<k;j++)
          {
              if(s[i]==all[j])f=1;
              tmp.pb(all[j]);
              int mx=0;
              for(int l=0;l<tmp.size();l++)
              {
                  int r;
                  for(r=l;r<tmp.size();r++)
                  {
                      if(tmp[r]!=s[r-l])break;
                  }
                  if(r==tmp.size())
                  {
                      mx=max(mx,r-l);
                     // break;
                  }
              }
              //cout<<mx<<endl;
              org.a[i][mx]++;
              tmp.pop_back();
          }
          if(f==0)flg=1;
          tmp.push_back(s[i]);
      }
      org=org.pow(n);
      int ans=0;
      for (int i = 0; i < m; i++) {

        ans=(ans+org.a[0][i])%mod;
      }
      ans=(ans+mod)%mod;
      //if(flg)ans=(ans+org.a[0][m])%mod;
      cout<<"Case "<<cs<<": "<<ans<<endl;

  }
  return 0;
}
