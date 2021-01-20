#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n;
string s[N];
int a[N];
int dp[N];

int f(int idx, int x){
    if(idx == n)
        return 0;
    if(dp[idx] != -1 )
        return dp[idx];
    if(a[idx] != x)
        dp[idx] = 0;
    else
        dp[idx] = 1 + f(idx + 1 , x);
    return dp[idx];
}

int main()
{
    int testcase;
    string temp;
    getline(cin , temp);
    stringstream ss(temp);
    ss >> testcase;
    getline(cin , temp);
    int len;
    int ans;
    while(testcase --){
        n = 0;
        ans = 0;
        while(getline(cin , s[n]) , s[n++] != "");
        for(int i = 0 ; i < n ; i++){
            memset(a , 0  , sizeof a);
            for(int j = i ; j < n ; j++){
                len = j - i + 1;
                for(int k = 0 ; k < n ; k++){
                    a[k]+= (s[j][k] - '0');
                }
                memset(dp, -1 , sizeof dp);

                for(int k = 0 ; k < n ; k++){
                    ans = max(ans, f(k , len) * len);
                }
            }
        }
        cout<<ans<<endl;
        if(testcase != 0)
            cout<<endl;
    }
    return 0;
}
