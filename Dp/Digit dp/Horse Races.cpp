#include <bits/stdc++.h>
using namespace std;
int num[10003];
int a, b, d, k;
int DP[1002][1002][2];
#define M 1000000007
long long int call(int pos, int cnt,int yo,int f){
    if(!pos) return yo;
    if(f&&DP[pos][cnt][yo] != -1) return DP[pos][cnt][yo];
    int res = 0;
    int LMT;

    if(f == 0){
        LMT = num[pos];
    } else {
        LMT = 9;
    }
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int nyo=0;
        if(f == 0 && dgt < LMT) nf = 1;
        if(dgt == 4||dgt==7)
        {
            if(cnt&&(cnt-pos)<=k)nyo=1;
            res=(res%M+call(pos-1,pos,yo||nyo,nf)%M)%M;
        }
        else
        {
            res=(res%M+call(pos-1,cnt,yo||nyo,nf)%M)%M;
        }
    }
    if (f==0)return res;
    return DP[pos][cnt][yo] = res;
}
long long int solve(string s){
    int len=s.size(),i;
    for(i=0;i<len;i++)
        num[len-i]=s[i]-'0';
    long long int res = call(len,0,0,0);
    return res;
}

int main () {

    int i,j,lst,t;
     memset(DP, -1, sizeof(DP));
    cin>>t>>k;
    while(t--)
    {
        string s,p;
        cin>>s>>p;
        j=0;
        lst=-1;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='4'||s[i]=='7')
            {
                if(lst!=-1&&(i-lst)<=k)
                {
                    j=1;
                    break;
                }
                lst=i;
            }
        }
        cout<<(solve(p)-solve(s)+j+M)%M<<endl;
    }
}
