//https://lightoj.com/problem/tiles
#include<bits/stdc++.h>
using namespace std;

const int mod = 10007;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc,cs;
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k;
      cin >> n ;
      Mat org(4, 4);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                if(i==0)org.a[i][j]=1;
                else org.a[i][j]=0;
        }
      }
      org.a[1][2]=org.a[1][3]=org.a[2][1]=org.a[2][3]=org.a[3][0]=1;
      Mat b(4, 1);
      b.a[0][0]=b.a[3][0]=1;
      b.a[1][0]=b.a[2][0]=0;
      org=org.pow(n);
      Mat ans=org*b;
     // for(int i=0;i<=3;i++)cout<<ans.a[i][0]<<endl;
      cout<<"Case "<<cs<<": "<<ans.a[3][0]<<endl;
  }
  return 0;
}
