#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair(int , int)

const int N = 105;

int row, col;
int a[N][N];
int sum[N];
int dp[N];

int f(int idx){
    if(idx == row)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    if(sum[idx] >= 1)
        return 0;
    dp[idx] = 1 + f(idx + 1);
    return dp[idx];
}

int main()
{
    int ans;
    while(cin >> row >> col , row != 0){
        ans = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                cin >>a[i][j];
            }
        }

        for(int i = 0 ; i < col ; i++){
            memset(sum, 0 , sizeof sum);
            for(int j = i ; j < col ; j++){
                for(int k = 0 ; k < row ; k++){
                    sum[k] += a[k][j];
                }
                memset(dp, -1 , sizeof dp);
                for(int k = 0 ; k < row ; k++){
                    if(sum[k] == 0){
                        ans = max(ans, f(k) * (j-i+1));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
