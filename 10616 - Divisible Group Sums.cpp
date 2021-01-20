#include <bits/stdc++.h>

using namespace std;

string s;
long long dp[64][64];
long long f(int i,int j){
    if(i==j)
        return 1;
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        dp[i][j]= 1+f(i+1,j)+f(i,j-1);
    else
        dp[i][j]= f(i+1,j)+f(i,j-1)-f(i+1,j-1);
    return dp[i][j];

}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases){
        memset(dp,-1,sizeof dp);
        cin>>s;
        cout<<f(0,s.size()-1)<<endl;
        testCases--;
    }
    return 0;
}
