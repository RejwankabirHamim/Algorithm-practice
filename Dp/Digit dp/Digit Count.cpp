#include <bits/stdc++.h>
using namespace std;
int a, b, d, k;
int DP[12][12];
vector<int>v;
int call(int pos, int cnt){
    if(pos == b){
        return 1;
    }
    if(DP[pos][cnt] != -1) return DP[pos][cnt];
    int res = 0;
    for(int dgt = 0; dgt<a; dgt++){
        if((pos!=0||v[dgt]!=0)&&(abs(v[dgt]-cnt)<=2||pos==0)) res += call(pos+1,v[dgt]);
        //cout<<pos<<" "<<res<<" "<<dgt<<endl;
    }
    return DP[pos][cnt] = res;
}
int main () {

    int t,z;
    cin>>t;
    z=t;
    while(t--)
    {
        memset(DP,-1,sizeof DP);
       cin >> a >> b ;
       v.resize(a);
       for(int i=0;i<a;i++)cin>>v[i];
       cout <<"Case "<<z-t<<": "<<call(0,0)<< endl;
       v.clear();
    }


    return 0;
}
