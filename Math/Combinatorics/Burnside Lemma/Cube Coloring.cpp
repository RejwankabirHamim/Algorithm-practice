//https://www.hackerrank.com/contests/srbd-code-contest-2023-round-2/challenges/rubiks-cube-coloring/problem
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M   998244353 //1000000007  //
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
ll ar[500005],br[1000005],cr[1000005],dr[1000005];
int main()
{
    //fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        char ch[6];
        map<char,int>mp;
        fr(i,5,0)cin>>ch[i],mp[ch[i]]++;
        sort(ch,ch+6);
        set<string>st[7];
        do{
            fr(i,(1<<6)-1,1)
            {
               // dbg(i);
                string s;
                fr(j,5,0)
                {
                    if(i&(1<<j))s.pb(ch[j]);
                }
                st[s.size()].insert(s);
            }

        } while (next_permutation(ch, ch+6));
        x=0;
        x+=st[6].size();
        z=0;
        for(auto U:st[4])
        {
            map<char,int>mp1;
            mp1[U[0]]+=2,mp1[U[1]]+=2,mp1[U[2]]++,mp1[U[3]]++;
            k=0;
            for(auto [u,v]:mp)k+=(mp[u]!=mp1[u]);
            if(k==0)z++;
        }
        x+=(z*3);
        z=0;
        for(auto U:st[2])
        {
            map<char,int>mp1;
            mp1[U[0]]+=3,mp1[U[1]]+=3;
            k=0;
            for(auto [u,v]:mp)k+=(mp[u]!=mp1[u]);
            if(k==0)z++;
        }
        x+=(z*8);
        z=0;
        for(auto U:st[3])
        {
            map<char,int>mp1;
            mp1[U[0]]+=4,mp1[U[1]]++,mp1[U[2]]++;
            k=0;
            for(auto [u,v]:mp)k+=(mp[u]!=mp1[u]);
            if(k==0)z++;
        }
        x+=(z*6);
        z=0;
        for(auto U:st[3])
        {
            map<char,int>mp1;
            mp1[U[0]]+=2,mp1[U[1]]+=2,mp1[U[2]]+=2;
            k=0;
            for(auto [u,v]:mp)k+=(mp[u]!=mp1[u]);
            if(k==0)z++;
        }
        x+=(z*6);
        x/=24;
        //z=(st[6].size()+st[4].size()*3+st[3].size()*12+8*st[2].size());
        cout<<x<<endl;
    }
}
