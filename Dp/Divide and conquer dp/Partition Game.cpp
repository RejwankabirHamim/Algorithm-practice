#include<bits/stdc++.h>
using namespace std;
long long int m, n,a[40006],cur_l=1,cur_r=0,ans,nxt[40005],pre[40005],b[40005];
vector<long long> dp_before(1), dp_cur(1);
void remove(int idx,int chk)
{
    int x;
    if(chk)x=nxt[idx];
    else x=pre[idx];
    if(chk&&x<=cur_r)ans-=(x-idx);
    else if(chk==0&&x>=cur_l)ans-=(idx-x);
}
void add(int idx,int chk)
{
    int x;
    if(chk)x=nxt[idx];
    else x=pre[idx];
    if(chk&&x<=cur_r)ans+=(x-idx);
    else if(chk==0&&x>=cur_l)ans+=(idx-x);
}
long long C(int i, int j)
{
    while (cur_l >i) {
            cur_l--;
            add(cur_l,1);
        }
        while (cur_r < j) {
            cur_r++;
            add(cur_r,0);
        }
        while (cur_l <i) {
            remove(cur_l,1);
            cur_l++;
        }
        while (cur_r > j) {
            remove(cur_r,0);
            cur_r--;
        }
    return ans;

}
// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};
    for (int k = optl; k <= min(mid, optr); k++) {
        best =min(best, {dp_before[k - 1] + C(k,mid), k});

    }

    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
long long int solve() {
    dp_before[0]=dp_cur[0]=0;
    for (int i =1; i <= m; i++)
        dp_before[i] = C(1, i);//,cout<<dp_before[i]<<" ";
    for (int i = 2; i <= n; i++) {
        compute(1, m, 1, m );
        dp_before = dp_cur;
    }

    return dp_before[m];
}
int main()
{
    long long int i,j,k;
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>m>>n;
     dp_before.resize(m+1);
     dp_cur.resize(m+1);
     for(i=1;i<=m;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
    {
        pre[i]=b[a[i]];
        b[a[i]]=i;
    }
    for(i=1;i<=m;i++)b[i]=m+1;
    for(i=m;i>=1;i--)
    {
        nxt[i]=b[a[i]];
        b[a[i]]=i;
    }
    cout<<solve()<<endl;
}


