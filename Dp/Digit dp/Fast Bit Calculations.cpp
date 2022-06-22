#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll int> num;
ll int a, b, d, k;
ll int DP[33][33][2][2];
ll int call(int pos, int cnt,int f,int pre){
    if(pos == num.size()){
        return cnt;
    }
    if(DP[pos][cnt][f][pre] != -1) return DP[pos][cnt][f][pre];
    ll int res = 0;
    int LMT;
    if(f == 0){
        LMT = num[pos];
    } else {
        LMT = 1;
    }
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == 1&&pre==1)
        {
            if(pre==1)ncnt++;
            res+=call(pos+1,ncnt,nf,dgt);
        }
        else
        res +=call(pos+1, ncnt, nf,dgt);
    }

    return DP[pos][cnt][f][pre] = res;
}
ll int solve(ll int b){
    num.clear();
    while(b>0){
        num.push_back(b%2);
        b/=2;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity
    memset(DP, -1, sizeof(DP));
    ll int res = call(0, 0, 0,0);
    return res;
}

int main ()
{
    ll int i,j,t,x,y,z;
    cin>>t;
    z=t;
    while(t--)
    {
        cin>>x;
        ll int res =solve(x);
        cout<<"Case "<<z-t<<": "<<res<< endl;
    }
    return 0;
}
