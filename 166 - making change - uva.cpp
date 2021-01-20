#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
//const int N;
//const ll INF;
//const ll NINF;
const int MAX = 1e9;

int coin[] = {200, 100, 50, 20, 10, 5};
int num[8];
int dp[1005][8];
int dp_222[1005][8];

int pay(int m, int idx){
    if( m == 0 )
        return 0;
    if( idx == 6 || m < 0 )
        return -2;

    if( dp_222[m][idx] != -1 )
        return dp_222[m][idx];
    int temp;
    if( num[idx] > 0 ){
        num[idx]--;
        temp = pay( m - coin[idx] , idx );
        num[idx]++;
        if(temp != -2){
            dp_222[m][idx] = temp + 1;
            return temp + 1;
        }
    }
    temp = pay( m , idx+1 );
    if(temp != -2){
        dp_222[m][idx] = temp;
        return temp;
    }
    dp_222[m][idx] = -2;
    return -2;
}

int res(int m , int idx){
    if(m == 0)
        return 0;
    if( idx == 6 || m < 0)
        return MAX;

    if(dp[m][idx] != -1)
        return dp[m][idx];
    int ans = 1 + res(m - coin[idx] , idx);
    ans = min (ans , res(m , idx + 1));
    dp[m][idx] = ans;
    return ans;
}


int main()
{
    ll sum = 0;
    int p1, p2;
    int money;
    memset(dp, -1 , sizeof dp);
   // cout<<res(5 , 0)<<endl;
    while(true){
        sum = 0;
        for(int i = 0 ; i < 6 ; i++){
            scanf("%d" , &num[5-i]);
            sum += num[5-i] * coin[5-i];
        }
        if(sum == 0)
            break;
        memset(dp_222 , -1, sizeof dp_222);
        scanf("%d.%d", &p1, &p2);
        money = p1 * 100 + p2;
        sum = 1000;
        int ans = MAX;
        int temp;
        for(int i = money ; i <= sum ; i+=5 ){
            temp = pay(i , 0);
            if(temp == -2)
                continue;
            temp += res(i - money , 0);
            //cout<<i <<' '<< i - money<<' '<<pay(i, 0) << ' '<<res(i - money , 0)<<endl;
            ans = min(ans, temp);
        }
        cout<<setw(3)<<ans<<endl;
    }
    return 0;
}
