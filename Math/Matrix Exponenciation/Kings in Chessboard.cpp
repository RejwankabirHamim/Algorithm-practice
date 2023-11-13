//https://lightoj.com/problem/kings-in-chessboard
#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define pb push_back
const int mod = 4294967296;
 int mod_inverse( int x, int p)//x is fact[i] and p is M-2
{
    int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}
int power(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
int Gauss(vector<vector<int>> a, vector<int> &ans){
  int n = a.size(), m = (int)a[0].size() - 1;
  vector <int> pos(m, -1);
  int free_var = 0;
  const long long MODSQ = (long long)mod * mod;
  int det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    for (int k = row; k < n; k++) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {det = 0; continue;}
    for (int j = col; j <= m; j++) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : mod - det;
    det = 1LL * det * a[row][col] % mod;
    pos[col] = row;
    int inv = power(a[row][col], mod - 2);
    for (int i = 0; i < n && inv; i++){
      if (i != row && a[i][col]) {
        int x = ((long long)a[i][col] * inv) % mod;
        for (int j = col; j <= m && x; j++){
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((long long)a[row][j] * x)) % mod;
        }
      }
    }
    row++; ++rank;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; i++){
    if (pos[i] == -1) free_var++;
    else ans[i] = ((long long)a[pos[i]][m] * power(a[pos[i]][i], mod - 2)) % mod;
  }
  for (int i = 0; i < n; i++) {
    long long val = 0;
    for (int j = 0; j < m; j++) val = (val + ((long long)ans[j] * a[i][j])) % mod;
    if (val != a[i][m]) return -1; //no solution
  }
  return free_var; //has solution
}
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
  Mat init(45,45);
  int mp[1026];
  for(i=0;i<=1024;i++)mp[i]=-1;
  int hs=0;
  for(i=0;i<1024;i++)
  {
      int cal=0;
      for(j=0;j<10;j++)
      {
          if(i&(1<<j))cal++;
      }
      if(cal==2)mp[i]=hs++;
  }
  for(i=0;i<1024;i++)
  {
      if(mp[i]==-1)continue;
      for(j=0;j<1024;j++)
      {
          if(mp[j]==-1)continue;
          vector<int>fst;
          for(int l=0;l<10;l++)
          {
              if(i&(1<<l))fst.pb(l);
              if(j&(1<<l))fst.pb(l);
          }
          int flg=1;
          for(int k=0;k<fst.size()-1;k++)
          {
              if(abs(fst[k+1]-fst[k])<=1)
              {
                  flg=0;
                  break;
              }
          }
          init.a[mp[i]][mp[j]]=flg;
      }
  }
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k,x,y;
      cin >> n ;
      int ans=0;
      if(n==1)ans=36;
      else
      {
          Mat tot=init.pow(n-1);
          for(i=0;i<45;i++)
          {
              for(j=0;j<45;j++)ans=(ans+tot.a[i][j])%mod;
          }
          ans=(ans+mod)%mod;
      }
      cout<<"Case "<<cs<<": "<<ans<<endl;

  }
  return 0;
}
