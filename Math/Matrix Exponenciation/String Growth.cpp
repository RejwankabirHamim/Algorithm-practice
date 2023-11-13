//https://lightoj.com/problem/string-growth
#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define pb push_back
const int mod = 1000000007;
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
const int INF = 2;
int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) ==0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = (a[i][col] * mod_inverse( a[row][col],mod-2))%mod;
                for (int j=col; j<=m; ++j)
                    a[i][j] =( a[i][j]- a[row][j] * c)%mod;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (a[where[i]][m] * mod_inverse( a[where[i]][i],mod-2))%mod;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum =(sum+ ans[j] * a[i][j])%mod;
        if (abs (sum - a[i][m]) )
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    for(int i=0;i<ans.size();i++)ans[i]=(ans[i]+mod)%mod;
    return 1;
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
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k,x,y;
      cin >> n>>x>>m>>y>>k ;
      if(n>m)
      {
          swap(n,m);
          swap(x,y);
      }
      Mat org(2, 2);

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
                org.a[i][j]=1;
        }
      }
      org.a[1][1]=0;
      Mat tmp=org.pow(n-1);
      Mat tmp1=org.pow(m-1);
      vector< vector<int> >v(2);
      v[0].pb(tmp.a[0][0]+tmp.a[1][0]);
      v[0].pb(tmp.a[0][1]+tmp.a[1][1]);
      v[0].pb(x);

      v[1].pb(tmp1.a[0][0]+tmp1.a[1][0]);
      v[1].pb(tmp1.a[0][1]+tmp1.a[1][1]);
      v[1].pb(y);
      vector<int>ans;
      int tp=gauss(v,ans);
      if(ans[0]+ans[1]>x||x>y)tp=0;
       cout<<"Case "<<cs<<": ";
      if(tp!=1)cout<<"Impossible"<<endl;
      else
      {
          org=org.pow(k-1);
          Mat nw(2,1);
          nw.a[0][0]=ans[0];
          nw.a[1][0]=ans[1];
          Mat an=org*nw;
          int fnl=(((an.a[0][0]+an.a[1][0])%mod)+mod)%mod;
          cout<<fnl<<endl;
      }

  }
  return 0;
}
