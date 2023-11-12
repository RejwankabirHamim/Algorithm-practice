//https://lightoj.com/problem/summing-up-powers
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int ncr[53][53];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i,j;
  for(i=0;i<=50;i++)ncr[i][0]=1;
  for(i=1;i<=50;i++)
  {
      for(j=1;j<=i;j++)ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
  }
  int tc,cs;
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k;
      cin >> n>>k ;
      Mat org(k+2, k+2);

      for (int i = 0; i < k+2; i++) {
        for (int j = 0; j < k+2; j++) {
                org.a[i][j]=0;
        }
      }
      for (int i = 0; i < k+1; i++) {
        for (int j = i; j < k+1; j++) {
                org.a[i][j]=ncr[k-i][j-i];
        }
      }
      org.a[k+1][0]=org.a[k+1][k+1]=1;
      org=org.pow(n);
      Mat tmp(k+2,1);
      for(i=0;i<k+1;i++)tmp.a[i][0]=1;
      tmp.a[i][0]=0;
      tmp=org*tmp;
      cout<<"Case "<<cs<<": "<<tmp.a[k+1][0]<<endl;

  }
  return 0;
}
