#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int dis;
int wind[12][1005];
int dp[1005][12];
const int MAX = 1e9;

int f(int idx , int h){
    if(h > dis - idx)
        return MAX;
    if(idx == dis)
        return 0;
    if(dp[idx][h] != -1)
        return dp[idx][h];

    dp[idx][h] = f(idx + 1 , h) + 30 - wind[h][idx];

    if(h != 0)
        dp[idx][h] = min (dp[idx][h] , f(idx + 1 , h - 1) + 20 - wind[h][idx] );

    if(h != 9)
        dp[idx][h] = min (dp[idx][h] , f(idx + 1 , h + 1) + 60 - wind[h][idx] );

    return dp[idx][h];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase--){
        memset(dp, -1 , sizeof dp);
        cin >> dis ;
        dis /= 100;
        for(int i = 9 ; i >= 0 ; i--){
            for(int j = 0 ; j < dis ; j++){
                cin >> wind[i][j];
            }
        }
        cout<<f(0 , 0)<<endl;
    }
    return 0;
}
