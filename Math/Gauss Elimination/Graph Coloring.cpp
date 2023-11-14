//https://lightoj.com/problem/graph-coloring
#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define ff first
#define ss second
#define pb push_back
int mod = 1000000007;
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
            return -1;
    }
    int tot=0;
    for (int i=0; i<m; ++i)
        if (where[i] == -1)tot++;
    return tot;
}
int adj[102][102];
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i,j;
  int tc,cs;
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k,x,y;
      cin >>n>>m>>k;
      mod=k;
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)adj[i][j]=0;
          adj[i][i]=-1;
      }
      for(i=1;i<=m;i++)
      {
          cin>>x>>y;
          adj[x][y]=1;
          adj[y][x]=1;
      }
      vector< vector<int>>v(n);
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
              v[i-1].pb(adj[i][j]);
          }
          v[i-1].pb(0);
      }
      vector<int>ans;
      y=gauss(v,ans);
      int an=0;
      if(y!=-1)
      {
          mod=1000000007;
          an=mod_inverse(k,y);
      }
      cout<<"Case "<<cs<<": "<<an<<endl;

  }
  return 0;
}
