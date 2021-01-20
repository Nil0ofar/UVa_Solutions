#include <bits/stdc++.h>

using namespace std;

#define ll long long

unsigned ll dp[65][65];

unsigned ll trib(int n, unsigned int bck){
    unsigned ll sum=1;
    if(n<=1)
        return 1;
    if(dp[n][bck] != -1)
        return dp[n][bck];
    for(int i=1;i<=bck;i++)
        sum+=trib(n-i,bck);
    dp[n][bck] = sum;
    return sum;
}

int main()
{
    int n , bck;
    memset(dp, -1 , sizeof dp);
    int testcase = 1;
    while(cin >> n >> bck){
        if(n > 60)
            break;
        bck = max(0 , bck);
        cout<<"Case "<<testcase++ <<": "<<trib(n , bck)<<endl;
        //printf("Case %d: %I64u\n" , testcase++ , trib(n,bck));    sare in wrong mikhordam :/ , i don't know why!
    }
    return 0;
}
