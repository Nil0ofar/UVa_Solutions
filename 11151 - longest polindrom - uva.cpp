#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

string s;
int dp[1001][1001];

int f(int i , int j){
    if(j < i)
        return 0;
    if(i == j)
        return 1;
    if(dp[i][j] != -1 )
        return dp[i][j];
    if(s[i] == s[j])
        dp[i][j] = 2 + f(i + 1 , j - 1);
    else{
        dp[i][j] = f(i + 1, j);
        dp[i][j] = max(dp[i][j] , f(i , j - 1));
    }
    return dp[i][j];
}

int main(){

    int testcase;
    getline(cin , s);
    stringstream ss(s);
    ss >> testcase;
    while(testcase--){
        getline(cin , s);
        if(s == ""){
            cout<<0<<endl;
            continue;
        }
        memset(dp, - 1, sizeof dp);
        cout<<f(0 , s.size() -1)<<endl;
    }
    return 0;
}
