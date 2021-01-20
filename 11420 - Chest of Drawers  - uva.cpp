#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n , s;

ll dp[70][70][3];

ll f(int idx , int needed , int last){
    if(needed < 0)
        return 0;
    if(idx == n){
        if(last == 1)
            needed --;
        if(needed == 0)
            return 1;
        return 0;
    }
    if(dp[idx][needed][last] != -1)
        return dp[idx][needed][last];

    ll  sum = f(idx + 1, needed , 0);
    if(last == 1)
        sum += f(idx + 1, needed -1 , 1);
    else
        sum += f(idx + 1 , needed, 1);
    dp[idx][needed][last] = sum;
    return sum;

}

int main()
{
    while(cin >> n >> s){
        if(n < 0)
            break;
        memset(dp, -1, sizeof dp);

        cout<<f(0 , s , 0)<<endl;
    }
    return 0;
}
