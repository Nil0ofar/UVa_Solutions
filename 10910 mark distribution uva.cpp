#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n , tt , p;
ll dp[75][75];

ll f(int idx, int t){
    //cout<<idx<<' '<<t<<endl;
    if(t < 0)
        return 0;
    if(idx == n){
        if(t == 0)
            return 1;
        return 0;
    }

    if(dp[idx][t] != -1)
        return dp[idx][t];

    ll sum = 0;
    for(int i = 0 ; i <= t ; i++){
        sum += f(idx + 1 , t - i);
    }

    dp[idx][t] = sum;
    return sum;
}

int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n >> tt >> p;
        memset(dp, -1 , sizeof dp);
        tt -= (n * p);
        cout<<f(0 , tt)<<endl;
    }
    return 0;
}
