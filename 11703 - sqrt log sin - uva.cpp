#include <bits/stdc++.h>

using namespace std;

#define ll long long

double p2(double x){
    return x*x;
}

int dp[1000005];
const int mod = 1000000;

ll f(int x){
    if(dp[x] != -1)
        return dp[x];
    ll res = f(floor(1.0*x - sqrt(x)));
    res += f(floor(log(x)));
    res += f(floor(x*1.0 * p2(sin(x))));
    res %= mod;
    dp[x] = res;
    return res;
}

int main()
{
    int x;
    memset(dp, -1 , sizeof dp);
    dp[0] = 1;
    while(cin >> x){
        if(x == -1)
            break;
        cout<<f(x)<<endl;
    }

    return 0;
}
