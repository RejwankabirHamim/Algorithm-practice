#include<bits/stdc++.h>
using namespace std;
int m, n,b[35006],a[35006],nxt[35006];
vector<long long> dp_before(1), dp_cur(1);
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
} *root[40005];
Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_sum(Vertex* v,Vertex* p, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
    {
        //cout<<l<<" "<<r<<" "<<v->sum<<" "<<p->sum<<endl;
        return v->sum-p->sum;
    }

    int tm = (tl + tr) / 2;
    return get_sum(v->l,p->l, tl, tm, l, min(r, tm))
         + get_sum(v->r,p->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
    {
        return new Vertex(v->sum+new_val);
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
long long C(int i, int j)
{
    return get_sum(root[j],root[i-1],0,m-1,0,i-1);

}
// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {0, -1};
    int x;
    for (int k = optl; k <= min(mid, optr); k++) {
        if(k==optl)x=C(k,mid);
        else
        {
            if(nxt[k-1]>mid)x--;
        }
        best =max(best, {dp_before[k - 1] + x, k});
        //if(mid==7)cout<<C(k,mid)<<" "<<k<<endl;
    }

    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int solve() {
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
    int i,j,k;
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>m>>n;
     dp_before.resize(m+1);
     dp_cur.resize(m+1);
     for(i=1;i<=m;i++)
        cin>>b[i];
    root[0]=build(a,0,m-1);
    for(i=1;i<=m;i++)
    {
        root[i]=update(root[i-1],0,m-1,a[b[i]],1);
        a[b[i]]=i;
    }
    for(i=1;i<=m;i++)a[i]=m+1;
    for(i=m;i>=1;i--)
    {
        nxt[i]=a[b[i]];
        a[b[i]]=i;
    }
    cout<<solve()<<endl;
}


