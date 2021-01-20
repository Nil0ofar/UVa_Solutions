#include <bits/stdc++.h>

using namespace std;

string s;
vector<char> ft,b;
int dp[1005][1005];
int f(int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        dp[i][j]=f(i+1,j-1);
    else{
        dp[i][j]=1+min(f(i,j-1),f(i+1,j));
    }
    return dp[i][j];
}

void print(int i,int j){
    if(i>j)
        return;
    if(i==j){
        ft.push_back(s[i]);
        return;
    }
    if(s[i]==s[j]){
        ft.push_back(s[i]);
        b.push_back(s[i]);
        print(i+1,j-1);
    }
    else{
        if(f(i,j)==1+f(i,j-1)){
            ft.push_back(s[j]);
            b.push_back(s[j]);
            print(i,j-1);
        }
        else{
            ft.push_back(s[i]);
            b.push_back(s[i]);
            print(i+1,j);
        }
    }
}
int main()
{
    while(cin>>s){
        ft.clear();
        b.clear();
        memset(dp,-1,sizeof dp);
        cout<<f(0,s.size()-1)<<' ';
        print(0,s.size()-1);
        for(int i=0;i<ft.size();i++)
            cout<<ft[i];
        for(int i=b.size()-1;i>=0;i--)
            cout<<b[i];
        cout<<endl;
    }
}
