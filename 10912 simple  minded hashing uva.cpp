#include <bits/stdc++.h>

using namespace std;

#define ll long long

int l , s;
int dp[30][30][900];

int f(int idx, int num, int remain){
    if(remain < 0)
        return 0;

    if(num == 0){
        if(remain == 0)
            return 1;
        return 0;
    }

    if(idx == 27)
        return 0;

    if(dp[idx][num][remain] != -1)
        return dp[idx][num][remain];

    if(remain < idx || num * 26 < remain)
        return 0;

    int sum = f(idx + 1, num , remain);
    sum += f(idx + 1, num - 1 , remain - idx);

    //cout<<idx<<' '<<num <<' '<<remain<<' '<<sum<<endl;

    dp[idx][num][remain] = sum;
    return sum;
}

int main()
{
    memset(dp, -1 , sizeof dp);
    int testcase = 1;
    while(cin >> l >> s){
        if(l == 0 && s == 0)
            break;
        cout<<"Case "<< testcase++ <<": ";
        if(l >= 30 || s >= 900)
            cout<<0<<endl;
        else
            cout<<f(1 , l , s)<<endl;
    }
    return 0;
}
