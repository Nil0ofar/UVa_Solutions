#include <bits/stdc++.h>

using namespace std;

string s;
int dp[1005][1005];
int f(int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        dp[i][j]=f(i+1,j-1);
    else{
        dp[i][j]=1+min(f(i+1,j-1),f(i+1,j));
        dp[i][j]=min(dp[i][j],1+f(i,j-1));
    }
    return dp[i][j];
}

int main()
{
    int testcases;
    int n=1;
    cin>>testcases;
    while(n<=testcases){
        memset(dp,-1,sizeof dp);
        cin>>s;
        cout<<"Case "<<n<<": "<<f(0,s.size()-1)<<endl;
        n++;
    }
}
