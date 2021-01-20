#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[30005][15];
int coin[] = {5 , 10 ,20 ,50 ,100 ,200 ,500 , 1000 , 2000, 5000 , 10000};

ll f(int money , int idx){
    if(money == 0)
        return 1;
    if(idx == 11 || money < 0)
        return 0;
    if(dp[money][idx] != -1)
        return dp[money][idx];
    ll ans = f(money - coin[idx] , idx);
    ans += f(money , idx +1);
    dp[money][idx] = ans;
    return ans;
}

int main()
{
    memset(dp, -1 , sizeof dp);
    int money ;
    int p1, p2;
    while(true){
        scanf("%d.%d" , &p1, &p2);
        money = p1 * 100 + p2;
        if(money == 0)
            break;
        cout<<setw(6)<<fixed<<setprecision(2)<<double(1.0*money/100.0)<<setw(17)<<f(money, 0)<<endl;
    }
    return 0;
}
