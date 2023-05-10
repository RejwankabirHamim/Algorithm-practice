//https://codeforces.com/problemset/problem/557/E
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M  998244353 // 1000000007  //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define endl '\n'
ll ar[500005],br[1000005],cr[1000005],dr[500005];
bool dp[5005][5005];

struct node{
    int ekhane;
    int tot;
    node *nxt[2];
    node()
    {
        ekhane=tot=0;
        for(int i=0;i<2;i++)
            nxt[i]=NULL;
    }

}*root;
void insert(string str,int len,int tot)
{
    node* cur=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(cur->nxt[id]==NULL)
            cur->nxt[id]=new node();
        cur=cur->nxt[id];
        cur->ekhane+=ar[i];
        cur->tot+=tot;
        tot-=ar[i];
    }

}
void search(int k)
{
    node* cur=root;
    while(1)
    {
        if(cur->ekhane>=k)return;
        k-=cur->ekhane;
        if(cur->nxt[0]==NULL)cur=cur->nxt[1],cout<<'b';
        else if(cur->nxt[0]->tot<k)k-=cur->nxt[0]->tot,cur=cur->nxt[1],cout<<'b';
        else cur=cur->nxt[0],cout<<'a';
    }
}
int main()
{
    //fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    //cin>>te;
    fr(w1,te,1)
    {
        string s;
        cin>>s>>k;
        n=s.size();
        fr(j,n,1)
        {
            fr(i,n-j,0)
            {
                if(s[i]==s[i+j-1]&&(j<=4||dp[i+2][j+i-3]))dp[i][i+j-1]=1;
            }
        }
        root=new node();
        fr(i,n-1,0)
        {
            string tmp;
            z=0;
            fr(j,n-1,i)tmp+=s[j],ar[j-i]=dp[i][j],z+=dp[i][j];
           // dbg(tmp);
            insert(tmp,n-i,z);
        }
        search(k);
        cout<<endl;
    }
}
