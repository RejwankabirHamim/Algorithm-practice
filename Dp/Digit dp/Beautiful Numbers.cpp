#include <bits/stdc++.h>
using namespace std;
int a, b, d, k;
#define M 1000000007
int DP[103][1026][12];
int call(int pos, int cnt,int lst){
    if(pos == b){
        if(cnt==(1<<a)-1)
         return 1;
       return 0;
    }
    if(DP[pos][cnt][lst]!= -1) return DP[pos][cnt][lst];
    int res = 0;
    if(cnt==0)
    {
        res=(res%M+call(pos+1,0,0))%M;
        for(int i=1;i<a;i++)
        {
            res=(res%M+call(pos+1,cnt|(1<<i),i))%M;
        }
    }
    else
    {
        if(lst<a-1)
            res=(res%M+call(pos+1,cnt|(1<<(lst+1)),lst+1))%M;
        if(lst>0)
             res=(res%M+call(pos+1,cnt|(1<<(lst-1)),lst-1))%M;

    }
    return DP[pos][cnt][lst] = res;
}
int main () {

    int t,z;
    cin>>t;
    while(t--)
    {
        memset(DP,-1,sizeof DP);
       cin >> a >> b ;
        cout<<call(0,0,0)<<endl;
    }
    return 0;
}
