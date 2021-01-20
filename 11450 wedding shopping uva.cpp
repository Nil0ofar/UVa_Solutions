#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int money, c;
vector<int> vec[25];
int dp[25][205];

int f(int idx, int sum){
    if(sum > money)
        return -1000000;
    if(idx == c)
        return 0;
    if(dp[idx][sum] != -1)
        return dp[idx][sum];
    for(int i = 0 ; i < vec[idx].size() ; i++){
        dp[idx][sum] = max(dp[idx][sum] , vec[idx][i]+ f(idx + 1 , sum + vec[idx][i]));
    }
    if(dp[idx][sum] == -1)
        dp[idx][sum] = -1000000;
    return dp[idx][sum];
}

int main(){
    int testcase;
    cin >> testcase;
    int k;
    int temp;
    while(testcase--){
        cin >> money >> c;
        for(int i = 0 ; i < c ; i++)
            vec[i].clear();
        for(int i = 0 ; i < c ; i++){
            cin >> k;
            while(k--){
                cin >> temp;
                vec[i].pb(temp);
            }
        }
        memset(dp , -1 , sizeof dp);
        f(0,0);
        if(dp[0][0] == -1000000)
            cout<<"no solution\n";
        else
            cout<<dp[0][0]<<endl;

    }
    return 0;
}
