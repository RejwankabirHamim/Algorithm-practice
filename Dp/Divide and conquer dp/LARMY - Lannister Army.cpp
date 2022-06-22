#include<bits/stdc++.h>
using namespace std;
long long int m, n,a[40006],cal[5005][5005],pre[5005][5005];
vector<long long> dp_before(1), dp_cur(1);
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};
    for (int k = min(mid, optr); k >=optl; k--) {
        best =min(best, {dp_before[k - 1] + cal[k][mid], k});

    }

    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
long long int solve() {
    dp_before[0]=dp_cur[0]=0;
    for (int i =1; i <= m; i++)
        dp_before[i] = cal[1][i];//,cout<<dp_before[i]<<" ";
    for (int i = 2; i <= n; i++) {
        compute(1, m, 1, m );
        dp_before = dp_cur;
    }

    return dp_before[m];
}
int main()
{
    long long int i,j,k,t,x;
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>m>>n;
    dp_before.resize(m+1);
    dp_cur.resize(m+1);
    for(i=1;i<=m;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
    {
        for(j=i-1;j>=1;j--)
        {
            pre[j][i]=pre[j+1][i]+(a[i]^a[j]);
            //cout<<pre[j][i]<<" "<<(a[i]^a[j])<<" "<<i<<" "<<j<<endl;
        }
        //cout<<endl;
    }
    for(i=1;i<=m;i++)
    {
        for(j=i+1;j<=m;j++)
        {
            cal[i][j]=cal[i][j-1]+pre[i][j];
          //  cout<<cal[i][j]<<" ";
        }

    }
    cout<<solve()<<endl;
}



