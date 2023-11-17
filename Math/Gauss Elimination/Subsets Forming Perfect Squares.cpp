https://lightoj.com/problem/subsets-forming-perfect-squar
#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define ff first
#define ss second
#define pb push_back
int mod = 1000000007;
bool prime[303];
vector<int>all;
void seive_prime(int n)
{
    int i,j;
    prime[1]=1;
    for(i=4;i<=n;i+=2)
        prime[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(!prime[i])all.pb(i);
    }
}
const int N=2002;
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m];
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum =(sum+ ans[j] * a[i][j])%2;
        if ((sum - a[i][m]))
            return 0;
    }
    int tot=1;
    for (int i=0; i<m; ++i)
        if (where[i] == -1)tot=(tot*2ll)%mod;
    return tot;
}
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i,j;
  int tc,cs;
  seive_prime(300);
//  for(auto u:all)cout<<u<<endl;
  cin>>tc;
  for(cs=1;cs<=tc;cs++)
  {
      int n, m, k,x,y;
      cin >>n;
      int a[n+2];
      for(i=1;i<=n;i++)cin>>a[i];
      m=all.size();
      //cout<<m<<endl;
      vector< bitset<N> >v(m);
      bitset<N> ans;
      for(i=1;i<=n;i++)
      {
          for(j=0;j<m;j++)
          {
              x=0;
              while(a[i]%all[j]==0)x++,a[i]/=all[j];
              x%=2;
              v[j][i-1]=x;
          }
      }
      for(j=0;j<m;j++)v[j][n]=0;
      int cal=gauss(v,m,n,ans);
      cal=(cal-1)%mod;
      cout<<"Case "<<cs<<": "<<cal<<endl;

  }
  return 0;
}
