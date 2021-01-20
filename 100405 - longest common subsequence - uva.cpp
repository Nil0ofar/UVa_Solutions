#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

string s, t;
int dp[1005][1005];

int f(int i , int j){
    if(i == s.size() || j == t.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = f(i + 1 , j);
    ans = max(ans, f(i , j + 1));
    if(s[i] == t[j])
        ans = max(ans, 1 + f(i + 1 , j + 1));
    dp[i][j] = ans;
    return ans;
}

int main(){
    while(getline(cin , s)){
        getline(cin , t);
        memset(dp, -1 , sizeof dp);
        cout<<f(0 , 0)<<endl;
    }
    return 0;
}
